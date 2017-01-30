/*
 * complex/food, written by Coogan@Tubmud, February-March 1998
 * Added usage of basic/healing, Coogan, 13-Jan-2001
 *
 */

#pragma strong_types

#include <libs.h>
#include <message.h>
#include <grammar.h>
#include <event.h>
#include <prop/item.h>
#include <persistence.h>

inherit "basic/decay";
inherit "basic/math";
inherit "basic/healing";
inherit "complex/item";

private int alcohol_rate = 0;
private int pieces = 1;
private static status consumed;

private string eat_func_name;

private mixed eat_func;
private mixed eaten_message, eaten_all_message;
private string eater_mess;


void eat_action(object who, int how_much) { }


mixed query_eat_func() {
  return eat_func;
}

string query_eat_func_name() {
  return eat_func_name;
}

mixed query_eaten_message() {
  return eaten_message;
}

mixed query_eaten_all_message() {
  return eaten_all_message;
}

// Coogan, 18-Aug-1998, moved from obj/food to here
string query_eater_mess() {
  if (query_decay_stages() > 3) {  // added this switch(), Coogan, 09-Nov-1999
    switch (query_decay_level()) {
      case  0: return "Your stomach makes a rumbling sound.\n";
      case  1: return "Your stomach bulges.\n";
      default: break;
    }
  }
  return eater_mess;
}

string query_taste() {
  string t;
  t = item::query_taste();  // query_real_taste()->item::, Coogan, 22.04.02
  if (query_decay_stages() < 3)
    return t;
  switch(query_decay_level()) {
  case  0:
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "taste",
                                        " rotten.\n" })));
  case  1:
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "taste",
                                        " decayed.\n" })));
  }
  return t;
}

string query_smell() {
  string t;
  t = item::query_smell();  // query_real_smell()->item::, Coogan, 22.04.02
  if (query_decay_stages() < 3)
    return t;
  switch (query_decay_level()) {
  case  0:
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "smell",
                                        " rotten.\n" })));
  case  1:
    return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "smell",
                                        " decayed.\n" })));
  }
  return t;
}

int query_pieces() {
  return pieces;
}

status query_breakable() {
  return query_pieces() > 1;
}

int query_portion() {
  return query_encumbrance() / query_pieces();
}

int query_body_healing_rate() {
  return query_age_factorized(healing::query_body_healing_rate());
}

int query_mind_healing_rate() {
  return query_age_factorized(healing::query_mind_healing_rate());
}

int query_alcohol_rate() {
  return query_age_factorized(alcohol_rate);
}

int query_value() {
  int h;
  h = (query_body_healing_rate() + query_mind_healing_rate()) / 2;
  return item::query_value() || 4 * h + (h * h) / 10;
}

status query_consumed() {
  return consumed;
}

void set_eat_func(mixed e) {
  if (objectp(e)) {
    if (e == this_object())
      eat_func = 0;
    else {
      if (!clonep(e))
        eat_func = load_name(e);
      else
        eat_func = e;
    }
  }
  else
    eat_func = e;
}

void set_eat_func_name(string e) {
  eat_func_name = e;
}

void set_eaten_message(mixed e) {
  eaten_message = e;
}

void set_eaten_all_message(mixed e) {
  eaten_all_message = e;
}

void set_eater_mess(mixed s) {  // string to mixed, Coogan, 12-Nov-1998
  if (stringp(s)) {
    if (s[<1..] == "\n")
      s = s[0..<2];
  } else if (!pointerp(s))  // added possibility of complex message,
    return;                 // Coogan, 12-Nov-1998
  eater_mess = s;
}

void set_alcohol_rate(int rate) {
  alcohol_rate = rate;
}

void set_pieces(int p) {
  if (p > 0)
    pieces = p;
}

void set_consumed() {
  consumed = 1;
  set_name(0);
  set_short(0);
  set_encumbrance(0);
  set_persistence(PER_NO_PERSISTENCE);
}

void food_eaten() {
  mixed tmp;
  message(
    funcall(query_eaten_message() ||
            (({({ M_ROOM, environment(this_player()),
                  M_PL_THE, M_PL_VERB, "eat", " some of ", M_ME_THE, "." })}) +
              // added check of !tmp, Coogan, 17-Nov-1998
             ((stringp((tmp = query_eater_mess())) || !tmp) // Coogan, 12-Nov-1998
              ? ({({ M_WRITE, M_RAW, tmp || "Yum yum yum." })})
              : tmp
             ))));
  if ((tmp = query_taste()))
    send_message(({ M_WRITE, tmp[0..<2] }));
}

void food_eaten_all() {
  mixed tmp;
  message(
    funcall(query_eaten_all_message() ||
            (({({ M_ROOM, environment(this_player()),
                  M_PL_THE, M_PL_VERB, "eat", M_ME_THE, "." })}) +
              // added check of !tmp, Coogan, 17-Nov-1998
             ((stringp((tmp = query_eater_mess())) || !tmp) // Coogan, 12-Nov-1998
              ? ({({ M_WRITE, M_RAW, tmp || "Yum yum yum." })})
              : tmp
             ))));
  if ((tmp = query_taste()))
    send_message(({ M_WRITE, tmp[0..<2] }));
}

void rot_away() {
  object t;
  if (item::short()) {
    if (t = find_living_environment())
      send_message(({ M_TARGETS, t, M_ME_THE, M_ME_VERB, "rot", " away." }));
    else
      send_message(({ M_ROOM, (: get_room(this_object()) :),
                      M_ME_THE, M_ME_VERB, "rot", " away." }));
  }
  call_out(#'destruct, 0, this_object());
}

object copy_food() {
  object new, p, m;
  string *variables;
  int i;
  new = clone_object(load_name(this_object()));
  while (first_inventory(new))  // prevent cloning with inventory
    destruct(first_inventory(new));
  new->set_name(query_real_name());
  new->set_short(query_real_short());
  new->set_long(query_real_long());
  variables = decay::query_persistent_variables();
  for (i=sizeof(variables); i-->0; )
    call_other(new,"set_" + variables[i],
               call_other(this_object(),"query_" + variables[i]));
  new->set_smell(query_real_smell());
  new->set_taste(query_real_taste());
  new->set_pieces(query_pieces());
  new->set_value(query_value());
  new->set_encumbrance(query_encumbrance());
  new->set_alcohol_rate(query_alcohol_rate());
#if 1  // Coogan, 16-May-2001
  variables = healing::query_persistent_variables();
  for (i=sizeof(variables); i-->0; )
    call_other(new,"set_" + variables[i],
               call_other(this_object(),"query_" + variables[i]));
#else
  new->set_body_healing_rate(query_body_healing_rate());
  new->set_mind_healing_rate(query_mind_healing_rate());
#endif
  new->set_eater_mess(query_eater_mess());  // Coogan, 12-Nov-1998
  new->set_eaten_message(query_eaten_message());
  new->set_eaten_all_message(query_eaten_all_message());
  for (m = first_inventory(); m; m = next_inventory(m)) {
    if (!m->query_property(P_POISON))
      continue;
    p = clone_object(load_name(m));
    p->set_poison_type(m->query_poison_type());
    p->set_poison_speed(m->query_poison_speed());
    p->set_poison_drain_speed(m->query_poison_drain_speed());
    p->set_poison_drain_rate(m->query_poison_drain_rate());
    p->set_poison_time_left(m->query_poison_time_left());
    move_object(p, new);
  }
  return new;
}

void receive_eat_event(mapping e, string action, int prio) {
  object p, m, new;
  int enc;

  if (e[E_TARGET] != this_object())  // we are not mentioned
    return;
  if (e[E_HANDLED] || prio != EPRIO_HANDLE)
    return;
  e[E_HANDLED] = 1;

  if (e[E_BODY_HEALING_RATE] &&
      !e[E_AGENT]->test_eat_food(e[E_BODY_HEALING_RATE])) {
    e[E_SUCCESS] = 0;
    return;
  }

  if (e[E_ALCOHOL_RATE] &&
      !e[E_AGENT]->test_drink_alcohol(e[E_ALCOHOL_RATE], 1)) {
    send_message(({ M_TARGETS, e[E_AGENT], "The alcohol in ", M_OBJECT, M_THE,
                    this_object(), " is too much for you now!" }));
    e[E_SUCCESS] = 0;
    return;
  }

  enc = query_encumbrance();
  if (e[E_AMOUNT] >= enc)
    with_player(e[E_AGENT], #'food_eaten_all);
  else
    with_player(e[E_AGENT], #'food_eaten);

  if (e[E_ALCOHOL_RATE])
    e[E_AGENT]->drink_alcohol(e[E_ALCOHOL_RATE]);

#if 1  // Coogan, 13-Jan-2001
  if (e[E_BODY_HEALING_RATE]) {
    e[E_AGENT]->eat_food(e[E_BODY_HEALING_RATE]);
    e[E_AGENT]->reduce_hit_point(-e[E_BODY_HEALING_RATE]);
    e[E_AGENT]->restore_spell_points(e[E_MIND_HEALING_RATE]);
  }
  else {  // player ate something, stomach is fuller. Coogan, 29-Aug-2004
    e[E_AGENT]->add_stuffed(5);
  }
#else
  if (e[E_HEALING_RATE]) {
    e[E_AGENT]->eat_food(e[E_HEALING_RATE]);
    e[E_AGENT]->heal_self(e[E_HEALING_RATE]);
  }
#endif
  if (enc != e[E_AMOUNT]) {
    m = copy_food();  // this part of the food remains for the player
    for (p = first_inventory(); p; p = next_inventory(p))
      if (p->query_property(P_POISON))
        p->set_poison_rate(p->query_poison_rate() * e[E_AMOUNT] / enc);
    for (p = first_inventory(m); p; p = next_inventory(p))
      if (p->query_property(P_POISON))
        p->set_poison_rate(p->query_poison_rate() * (enc - e[E_AMOUNT]) / enc);
    m->set_encumbrance(query_encumbrance() - e[E_AMOUNT]);
    if (query_pieces() > 1)
      m->set_pieces(query_pieces() - e[E_AMOUNT] / query_portion());
    move_object(m, e[E_AGENT]);
  }
  while (first_inventory())
    move_object(first_inventory(), e[E_AGENT]);
  if (e[E_SUCCESS] && e[E_TARGET] && e[E_HANDLED])
    call_other(eat_func || this_object(),
               eat_func_name || "eat_action",
               e[E_AGENT], e[E_AMOUNT]);
  set_consumed();
  call_out(#'destruct, 20, this_object());
  return;
}

varargs status consume_food(int howmuch, string type) {
  // arg type added as this is called for a long time now by 
  // global/commands/consume; Coogan, 28-Aug-2006
  int a, b, m, p, new, percent;
  mapping e;

  if (howmuch == 0 || howmuch > query_encumbrance())
    howmuch = query_encumbrance();
  if (howmuch <= 0)
    return 0;
  percent = howmuch * 100 / query_encumbrance();
  a = query_alcohol_rate() * percent / 100;
  b = query_body_healing_rate() * percent / 100;
  m = query_mind_healing_rate() * percent / 100;
  if (!this_player())
    return 0;
  e = ([
         E_TYPE              : "eat"        ; "eat",
         E_TARGET            : this_object(); describe(this_object()),
         E_AGENT             : this_player(); this_player()->query_name(),
         E_RECIPIENT         : this_player(); this_player()->query_name(),
         E_ALCOHOL_RATE      : a            ; a,
         E_BODY_HEALING_RATE : b            ; b,
         E_MIND_HEALING_RATE : m            ; m,
         E_AMOUNT            : howmuch      ; howmuch,
         E_SUCCESS           : 1            ; 0,
      ]);
  send_event("eat", e, ({ environment(this_player()) }));
  return e[E_SUCCESS];
}

status id(string str) {
  return !consumed &&
         (item::id(str) || str == "food");
}

string short() {
  if (query_decaying() && !query_property(P_STATE_DESCRIPTION) && !random(10))
    log_file("state_description", load_name(this_object())+"\n");
#if 0
  if (query_decayed(1))
    return 0;
#else
  if (query_decayed())
    if (find_call_out("rot_away") == -1) {
      call_out("rot_away", to_int(60 * gauss_random()));
      set_persistence(PER_NO_PERSISTENCE);
    }
#endif
  return query_short();
}

varargs string query_long(string str) {
  return query_real_long() +  // removed arg 'str', Coogan, 27-Sep-2010
         (query_breakable()
          ? ("There " + ((pieces == 1) ? "is " : "are ") +
            LIB_LANGUAGE->word_number(query_pieces()) + " piece" +
            ((pieces == 1) ? "" : "s") + " left.\n")
          : "" );  // replaced 'mouthful' with 'pieces'
}

void configure() {
  item::configure();
  set_persistence(PER_KEEP_VARS,
                  ({ ({ "smell", "set_smell", "query_real_smell" }),
                     ({ "taste", "set_taste", "query_real_taste" }),
                     ({ "long",  "set_long",  "query_real_long" }) }) +
                  decay::query_persistent_variables() +
                  healing::query_persistent_variables() +
                  ({ "alcohol_rate", "pieces", "eat_func", "eat_func_name",
                     "eaten_message", "eaten_all_message" }));
#if 0  // Coogan, 09-Nov-1999
  set_name("food");
#endif
  set_short("a non-descript food");
  set_id(({ "food", query_real_short() }));
  set_encumbrance(900 + random(200));
  set_decay_rate(50000 + to_int(5000.0 * gauss_random()));
         // somewhat around 3 hours per decay stage. Coogan, 14-Mar-2006
  set_decay_stages(5);
  set_decay_descriptions(({ "rotten", "decayed", "edible", "fresh",
                            "very fresh" }));
  set_property(P_EATABLE);
#if 0  // Coogan, 19-Aug-1998
  add_to_property(P_STATE_DESCRIPTION, ({ 0,"query_decay_state_description" }));
#endif
  listen_event("eat", EPRIO_HANDLE, #'receive_eat_event);
}

void init() {
  item::init(); // Chameloid, 13-Feb-1999
  add_action_rule("break "G_OBJECT" into pieces", "break");
  add_action_rule("break "G_OBJECT,               "break");
}

status do_action(string action, mapping args) {
  object p, piece;
  int i;
  if (args[G_OBJECT] != this_object())
    return 0;
  switch (action) {
  case "break":
    if (query_breakable()) {
      send_message(({ M_PL_THE, M_PL_VERB, "break", M_ME_THE, M_ADVERBS,
                      " into ", LIB_LANGUAGE->word_number(query_pieces()),
                      " smaller pieces." }));
      for (i = 0; i < query_pieces(); i++) {
        piece = copy_food();
        for (p = first_inventory(piece); p; p = next_inventory(p))
          if (p->query_property(P_POISON))
            p->set_poison_rate(p->query_poison_rate() / query_pieces());
        piece->set_encumbrance (query_encumbrance()  / query_pieces());
        piece->set_alcohol_rate(query_alcohol_rate() / query_pieces());
        piece->set_body_healing_rate(query_body_healing_rate()/query_pieces());
        piece->set_mind_healing_rate(query_mind_healing_rate()/query_pieces());
        piece->set_pieces(1);
#if 1  // Coogan, 12-Nov-1998
        if (query_short()) {
          piece->set_short("a piece of " +
                           describe(query_short(), ARTICLE_NONE));
          piece->add_id("piece of " + query_short());
        }
        if (query_long()) {
          piece->set_long("This is a piece of " +
                          describe(query_short(), ARTICLE_NONE) + ".\n");
        }
        if (query_name()) {
          piece->add_id("piece of " + query_name());
        }
#endif
        move_object(piece, environment(this_object()));
      }
      destruct(this_object());
    }
    else {
      notify_fail(({({ M_WRITE, (query_plural() ? "These " : "This "),
                       M_NONE, M_OBJECT, this_object(),
                       M_VERB, "are", this_object(), " not breakable!" })}));
      return 0;
    }
    break;
  default:
    return 0;
  }
  return 1;
}

status drop(status silently) {
  return consumed;
}

void notify_move(object from, mixed to) {
  if (decay::start_decaying(from, to)) {
    add_to_property(P_STATE_DESCRIPTION,
                    ({ 0, "query_decay_state_description" }));
  }
}

