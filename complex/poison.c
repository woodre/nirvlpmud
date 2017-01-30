/*
 *
 * poison.c -- written by Chameloid and Coogan for Tubmud
 *
 */

#pragma strong_types

#include <describe.h>
#include <prop/item.h>
#include <message.h>
#include <event.h>
#include <persistence.h>
#include <wizlevels.h>

inherit "basic/poisonable";
inherit "complex/item";

private int time_left;

int query_poison_time_left() {
  int h;
  if (living(environment()) && (h = find_call_out("weaken_bearer") > -1))
    return h;
  if (!living(environment()) && (h = find_call_out("drain_poison") > -1))
    return h;
  return time_left;
}

int query_poison_rate() {
  if (environment() && environment()->query_property(P_LIQUID))
    return environment()->query_factorized(poisonable::query_poison_rate());
  return poisonable::query_poison_rate();
}

mixed query_auto_load() {
  return ({ load_name(this_object()),
            query_poison_rate(),
            query_poison_speed(),
            query_poison_drain_rate(), // poison_drain_speed is not nessessary
            query_poison_type(),       // if once activated
            query_poison_time_left() });
}

void set_poison_time_left(int t) {
  time_left = t;
}

void drain_poison() {
  if (!query_poison_drain_rate() || !query_poison_rate()) {
    destruct(this_object());
    return;
  }
  set_poison_drain_rate(query_poison_drain_rate() - 1);
  set_poison_rate(poisonable::query_poison_rate() - 1);
  remove_call_out("drain_poison");
  call_out("drain_poison", query_poison_drain_rate());
}

void poison_drained() {
  if (environment() && living(environment()))
    send_message(({ M_TARGETS, environment(), "You somehow feel better." }));
}

void poison_kill() {
  send_message(({ M_THE, environment(), M_VERB, "fall", environment(), " on ",
                  M_POSSESSIVE, environment(), " knees and ", M_VERB, "puke",
                  environment(), " a last time." }));
}

void bearer_weakened() {
  if (!environment())
    return;
  if (!random(4))
    send_message(({ M_THE, environment(), M_VERB, "puke", environment(),
                    "." }));
  send_message(({ M_TARGETS, environment(), "You don't feel good..." }));
  if (environment()->query_hp() <= 4 * query_poison_rate())
    send_message(({ M_TARGETS, environment(), "Not to say, almost dead!" }));
}

static void weaken_bearer() {
  if (environment() && living(environment()))
    if (environment()->query_hp() < query_poison_rate()) {
      poison_kill();
      environment()->hit_player(100000, this_object());  // should be enough
      destruct(this_object());
      return;
    }
    else {
      if (query_poison_drain_rate()) {
        bearer_weakened();
        environment()->heal_self(-query_poison_rate());
      }
      else {
        poison_drained();
        destruct(this_object());
      }
      set_poison_drain_rate(query_poison_drain_rate() - 1);
    }
  call_out("weaken_bearer", query_poison_speed());
}

varargs void init_arg(mixed args) {
  set_poison_rate(args[0]);
  set_poison_speed(args[1]);
  set_poison_drain_rate(args[2]);
  set_poison_type(args[3]);
  call_out("weaken_bearer", args[4]);
}

void stop_draining() {  // should only be called by a liquid
  if (environment() && !living(environment()) &&
      find_call_out("drain_poison") > -1 &&
      find_call_out("weaken_bearer") == -1)
    time_left = remove_call_out("drain_poison");
}

void start_draining() {  // should only be called by a liquid
  if (environment() && !living(environment()) &&
      find_call_out("drain_poison") == -1 &&
      find_call_out("weaken_bearer") == -1)
    call_out("drain_poison", time_left);
}

status prevent_move(object from, mixed to) {
  if (from && living(from))  // survive or die!
    return 1;
  return 0;
}

mixed query_property(string key, string it) { // Coogan, 04-Dec-2003
  if (key == P_DESTRUCT_ON_DEATH)
    return 1;
  return item::query_property(key, it);
}

void notify_move(object from, mixed to) {
  mapping e;

  if (living(environment())) {
    if (find_call_out("weaken_bearer") > -1) // no new event after relogin
      return;
    e = ([ E_TYPE        : "poison";             query_poison_type(),
           E_AGENT       : this_object();        this_object()->query_name(),
           E_TARGET      : environment();        environment()->query_name(),
           E_POISON_RATE : query_poison_rate();  query_poison_rate(),
           E_POISON_SPEED: query_poison_speed(); query_poison_speed(),
        ]);
    if (from)
      e += ([ E_FROM : from; describe(from, ARTICLE_NONE) ]);
    send_event("poison", e, ({ environment(to) ? environment(to) : to }));
  }
  else
    call_out("drain_poison",
             ((time_left > -1) ? time_left : query_poison_drain_speed()));
}

void receive_poison_event(mapping e, string type, int prio) {
  if (type != "poison" || prio != EPRIO_HANDLE || e[E_AGENT] != this_object())
    return;
  if (e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  while (remove_call_out("drain_poison") != -1)
    ;
  if (query_poison_rate())
    call_out("weaken_bearer", query_poison_speed());
  else
    destruct(this_object());
}

void receive_petrify_event(mapping e, string type, int prio) {
  if (type != "petrify" || prio != EPRIO_NOTICE || e[E_AGENT] != environment())
    return;
  time_left = remove_call_out("weaken_bearer");
}

void receive_depetrify_event(mapping e, string type, int prio) {
  if (type != "petrify" || prio != EPRIO_NOTICE || e[E_AGENT] != environment())
    return;
  if (time_left > -1)
    call_out("weaken_bearer", time_left);
}

void notify_destruct() {
  unlisten_event("petrify",   EPRIO_NOTICE, #'receive_petrify_event);
  unlisten_event("depetrify", EPRIO_NOTICE, #'receive_depetrify_event);
  unlisten_event("poison",    EPRIO_HANDLE, #'receive_poison_event);
}

void configure() {
  item::configure();
  set_persistence(__FILE__, PER_KEEP_VARS, ({
    PER_PERM_VAR + "poison_time_left",
    "poison_rate", "poison_speed", "poison_drain_rate", "poison_drain_speed",
    "poison_type",
    }));
  time_left = -1;
  set_poison_type(0);
  set_poison_rate(5);
  set_poison_speed(30);
  set_poison_drain_rate(50);
  set_poison_drain_speed(1000);
  set_property(P_POISON);
  set_property(P_NOT_DROPPABLE);
  set_property(P_NOT_PORTABLE);
  set_property(P_NOT_TOSSABLE);
  set_encumbrance(0);
  set_name("poison");
  set_short(0);
  set_long(0);
  set_id("poison");
  listen_event("petrify",   EPRIO_NOTICE, #'receive_petrify_event);
  listen_event("depetrify", EPRIO_NOTICE, #'receive_depetrify_event);
  listen_event("poison",    EPRIO_HANDLE, #'receive_poison_event);
}

status response(string str) {
  if (str)
    return 0;
  message("You are POISONED!\n");
  if (is_wizard(this_player()))
    send_message(({ M_INDENT, 14, M_WRITE,
            "Wizard knows: poison type        = ", query_poison_type(), "\n",
            "poison rate        = ", query_poison_rate(), "\n",
            "poison speed       = ", query_poison_speed(), "\n",
            "poison drain rate  = ", query_poison_drain_rate(), }));
  return 0;
}

void init() {
  if (query_poison_rate())
    add_action("response", "score");
}

