/*
 * a basic liquid.c -- written by Chameloid, Coogan and Alfe for Tubmud
 * Added usage of basic/healing, Coogan, 13-Jan-2001
 *
 */

#pragma strong_types

#include <prop/item.h>
#include <prop/room.h>
#include <message.h>
#include <event.h>

inherit "basic/healing";

private status invitro = 1;
private status consumed = 0;

private int portion = 100;
private int alcohol_rate = 0;
private int drying_rate = 0;
private int time_left;

private string drink_func_name;

private mixed drink_func;
private mixed drunken_message, drunken_all_message;
private mixed slurped_message, slurped_all_message;
private mixed sipped_message;

private mapping tracemakers = ([:0]);  // added :0, Coogan, 28-Aug-2003
private mapping traces = ([:1]);  // added :1, Coogan, 28-Aug-2003


// to be overloaded if needed
void drink_action(object player, int amount) { }

static string* query_persistent_variables() {  // Coogan, 16-May-2001
  return healing::query_persistent_variables() +
         ({ "drunken_message", "drunken_all_message",
            "slurped_message", "slurped_all_message",
            "sipped_message",
            "drink_func", "drink_func_name" });
}

mixed query_drink_func() {
  return drink_func;
}

string query_drink_func_name() {
  return drink_func_name;
}

mixed query_drunken_message() {
  return drunken_message;
}

mixed query_drunken_all_message() {
  return drunken_all_message;
}

mixed query_slurped_message() {
  return slurped_message;
}

mixed query_slurped_all_message() {
  return slurped_all_message;
}

mixed query_sipped_message() {
  return sipped_message;
}

status query_invitro() {
  return invitro;
}

mapping query_traces() {
  return traces;
}

mapping query_tracemakers() {
  return tracemakers;
}

int query_portion() {
  return portion;
}

int query_drying_rate() {
  return drying_rate;
}

static int query_amount_factorized(int fac) {
  int t;
  if (!query_drying_rate())
    return fac;
  if ((t = find_call_out("dry_away")) == -1)
    t = time_left;
  return to_int((to_float(fac) * to_float(t)) / to_float(query_drying_rate()));
}

int query_body_healing_rate() {
  return query_amount_factorized(healing::query_body_healing_rate());
}

int query_mind_healing_rate() {
  return query_amount_factorized(healing::query_mind_healing_rate());
}

int query_alcohol_rate() {
  return query_amount_factorized(alcohol_rate);
}

int query_drying_time_left() {
  return time_left;
}

status query_consumed() {
  return consumed;
}

void start_drying_away() {
  if (find_call_out("dry_away") > -1)
    return;
  if (environment() &&
      (!function_exists("query_open", environment()) ||
       environment()->query_open())) {
    if (!time_left)
      time_left = query_drying_rate();
    if (time_left) {
      call_out("dry_away", time_left);
    }
  }
}

void stop_drying_away() {
  if (find_call_out("dry_away") > 0)  // we only stop if there is time left
    time_left = remove_call_out("dry_away");
}

void set_drink_func(mixed d) {
  if (objectp(d)) {
    if (d == this_object())
      drink_func = 0;
    else {
      if (!clonep(d))
        drink_func = load_name(d);
      else
        drink_func = d;
    }
  }
  else
    drink_func = d;
}

void set_drink_func_name(string d) {
  drink_func_name = d;
}

void set_drunken_message(mixed d) {
  drunken_message = d;
}

void set_drunken_all_message(mixed d) {
  drunken_all_message = d;
}

void set_slurped_message(mixed s) {
  slurped_message = s;
}

void set_slurped_all_message(mixed s) {
  slurped_all_message = s;
}

void set_sipped_message(mixed s) {
  sipped_message = s;
}

void set_invitro(status i) {
  invitro = i;
  if (i)  // it's not nessessary to listen, if inside of containers
    unlisten_event("move", EPRIO_NOTICE, "receive_move_event");
  else
    listen_event("move", EPRIO_NOTICE, "receive_move_event");
}

void set_traces(mapping t) {
  traces = t;
}

void set_tracemakers(mapping t) {
  tracemakers = t;
}

void add_tracemaker(object p) {  // Coogan, 23-Aug-2002
  m_add(tracemakers, p);
}

void set_portion(int p) {
  portion = p;
}

void set_alcohol_rate(int rate) {
  alcohol_rate = rate;
}

void set_drying_rate(int rate) {
  int old_rate, left;

  if (!clonep())  // a blueprint should not dry away
    return;
  old_rate = drying_rate;
  left = find_call_out("dry_away") + 1;
  stop_drying_away();
  drying_rate = rate;
  //DEBUG_POINT("coogan", ({ left, time_left, find_call_out("dry_away") }));
  if (time_left == -1)
    time_left = rate;
  else
    time_left = rate - (old_rate - time_left);  
  if (drying_rate && environment() &&  // liquid was not drying, but now it does
      (!function_exists("query_open", environment()) ||
       environment()->query_open()))
    start_drying_away();
}

void set_time_left(int t) {
  time_left = t;
}

void set_consumed() {
  consumed = 1;
  set_invitro(1);
}

void liquid_dried_away() {
  send_message(({ M_ROOM, (: get_room(this_object()) :),
                  "The last drops of ", M_ME_THE, " dry away." }));
}

void dry_away() {
  if (!clonep())
    return;
  set_invitro(1); // nicer message
  liquid_dried_away();
  while (first_inventory())  // destructs all poisons
    destruct(first_inventory());
  destruct(this_object());
}

// the next function is called, if not the whole liquid shall be drunken
// or the drying is stopped in order to make handling with variables easier;
// it re-sets the several rates
void renew_liquid(mixed percent) {  // changed to float-computing,
  int t;                            // Coogan, 26-Aug-2002
  if (intp(percent))
    percent = to_float(percent);
  set_alcohol_rate(
    to_int((percent * to_float(query_alcohol_rate()))) / 100);
  set_body_healing_rate(
    to_int((percent * to_float(query_body_healing_rate()))) / 100);
  set_mind_healing_rate(
    to_int((percent * to_float(query_mind_healing_rate()))) / 100);
  if (query_drying_rate()) {
    if ((t = find_call_out("dry_away")) > 0)
      time_left = t;
    set_drying_rate(to_int((percent * to_float(time_left))) / 100);
  }
}

static void delete_all_drink_messages() {
  set_drunken_message(0);
  set_drunken_all_message(0);
  set_slurped_message(0);
  set_slurped_all_message(0);
  set_drink_func(0);
  set_drink_func_name(0);
  set_sipped_message(0);
}

status mix_liquid(object other_liquid) {
  object h;
  set_drying_rate (query_drying_rate()  + other_liquid->query_drying_rate());
  set_alcohol_rate(query_alcohol_rate() + other_liquid->query_alcohol_rate());
  set_body_healing_rate(query_body_healing_rate() +
                                      other_liquid->query_body_healing_rate());
  set_mind_healing_rate(query_mind_healing_rate() +
                                      other_liquid->query_mind_healing_rate());
  while ((h = first_inventory(other_liquid)))
    move_object(h, this_object());
  tracemakers += other_liquid->query_tracemakers();
  traces += other_liquid->query_traces();
  return 1;
}

object copy_liquid() {
  object new;
  new = clone_object(load_name(this_object()));
  while (first_inventory(new))  // prevent cloning with inventory
    destruct(first_inventory(new));
  new->set_drying_rate(query_drying_rate());
  new->set_alcohol_rate(query_alcohol_rate());
  new->set_body_healing_rate(query_body_healing_rate());
  new->set_mind_healing_rate(query_mind_healing_rate());
  return new;
}

status prevent_move(object from, mixed to) {
  return from && query_consumed() && living(from);
}

void notify_move(object from, object to) {
  while (remove_call_out("check_environment") >= 0)
    ;  // do nothing
  if (!query_consumed())
    call_out("check_environment", 0);
}

void check_environment() {
  mixed h, i, err;
  if (environment())
    if (living(environment())) {
      if (consumed)
        return;
      set_invitro(1);  // just to let the next message be nicer
      send_message(({ M_ROOM, environment(environment()), M_ME_THE,
                      M_ME_VERB, "drip", " down from ", environment(), "." }));
      if (transfer(this_object(),environment(environment())))
        raise_error("Liquid can't drop down from living.\n");
    } else {  // env is not living
      if (!environment(environment())) {  // in a blueprint?
        if (environment()->query_container_name()) { // a bottle's blueprint?
          set_invitro(1);
          return;                                    // do nothing
        }
        set_invitro(0);                              // a room!
        if (find_call_out("dry_away") == -1)
          start_drying_away();
        if ((h = environment()->query_property(P_LIQUID_GROUND)) ||
            environment()->query_property(P_UNDER_WATER)) {
          send_message(({ M_ME_THE, M_ME_VERB, "vanish" }) +
                       (intp(h) ? ({ }) : ({ " in ", M_THE, h })) + ({ "." }));
          while (first_inventory())
            destruct(first_inventory());
          destruct(this_object());
        } else if (h = environment()->query_property(P_NO_GROUND)) {
          send_message(({ M_ME_THE, M_ME_VERB, "drop", " further down and ",
                          M_ME_VERB, "vanish", "." }));
          if (!(err=catch(load_object(h)))) {
            send_message(({ M_ROOM, h, "Suddenly, ", M_ME, M_ME_VERB, "drop",
                            " down from above." }));
            move_object(this_object(), h);
          } else {  // error case, room below could not be loaded
            while (first_inventory())
              destruct(first_inventory());
            destruct(this_object());
            raise_error(err);  // throw it again
          }
        }
      } else {  // env is a container
        set_invitro(1);
        // by putting a liquid into a container, all traces of it vanish
        traces = ([:1]);  // added :0, Coogan, 28-Aug-2003
        tracemakers = ([:0]);  // added :0, Coogan, 28-Aug-2003
        if (call_resolved(&h, environment(), "query_open") && !h) {
          stop_drying_away();
          renew_liquid(100);
        }
      }
    }
  if (sizeof(h = filter_objects(all_inventory(environment()) -
                                ({ this_object() }),
                                "query_property", P_LIQUID)))
    for (i = sizeof(h); i--; )
      if (!mix_liquid(h[i]))  // did find a bigger liquid?
        break;
}

void notify_destruct() {
  remove_call_out("dry_away");
}

int query_timeleft() {
  return find_call_out("dry_away");
}

