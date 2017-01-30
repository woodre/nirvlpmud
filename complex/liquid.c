/*
 * complex/liquid.c
 *
 * written by Chameloid, Coogan and Alfe for Tubmud, Oct 97 - Apr 98
 * Added usage of basic/healing, Coogan, 13-Jan-01
 *
 */

#pragma strong_types

#include <persistence.h>
#include <prop/item.h>
#include <grammar.h>
#include <message.h>
#include <describe.h>
#include <gender.h>
#include <libs.h>
#include <event.h>

#define DROPS       5000
#define PUDDLE     10000

inherit "basic/decay";  // for becoming stale
inherit "basic/liquid";
inherit "complex/item";

private int dirty = 0;

int query_encumbrance() {
  return query_amount_factorized(item::query_encumbrance());
}

int query_body_healing_rate() {
  return query_age_factorized(liquid::query_body_healing_rate());
}

int query_mind_healing_rate() {
  return query_age_factorized(liquid::query_mind_healing_rate());
}

int query_alcohol_rate() {
  return query_age_factorized(liquid::query_alcohol_rate());
}

int query_value() {
  int h;
  h = (query_body_healing_rate() + query_mind_healing_rate()) / 2;
  return item::query_value() || 4 * h + (h * h) / 10;
}

int query_dirty() {
  return dirty;
}

string query_taste() {
  if (query_decay_stages() < 5)
    return item::query_taste();  // Coogan, 22-Apr-2002
  switch (query_decay_level()) {
  case  0: return "extremely dull";
  case  1: return "very stale";
  case  2: return "stale";
  case  3: return "a bit stale";
  default: return item::query_taste();
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 27-Mar-2011
}

void set_dirty(int d) {
  dirty = d;
}

void set_consumed() {
  liquid::set_consumed();
  set_short(0);
  set_long(0);
  set_persistence(PER_NO_PERSISTENCE);  // !!
}

void start_drying_away() {
  object o;
  if (find_call_out("dry_away") > -1)
    return;
  liquid::start_drying_away();
  if (find_call_out("dry_away") > 0)
    for (o = first_inventory(); o; o = next_inventory(o))
      if (o->query_property(P_POISON))  // start poison draining in liquids
        o->start_draining();            // in open bottles
}

void stop_drying_away() {
  object o;
  if (find_call_out("dry_away") > 0) {  // we only stop if there is time left
    liquid::stop_drying_away();
    for (o = first_inventory(); o; o = next_inventory(o))
      if (o->query_property(P_POISON))  // stop poison draining in liquids in
        o->stop_draining();             // closed bottles
  }
}

// the next function is called, if not the whole liquid shall be drunken
// or the drying is stopped in order to make handling with variables easier;
// it re-scales encumbrance to 100 percent, and re-sets the several rates
void renew_liquid(mixed percent) {  // changed to float-computing, Coogan,
  object m;                         // 26-Aug-2002
  if (intp(percent))
    percent = to_float(percent);
  liquid::renew_liquid(percent);
  for (m = first_inventory(); m; m = next_inventory(m))
    if (m->query_property(P_POISON))
      m->set_poison_rate(
           to_int((percent * to_float(m->query_poison_rate())) / 100.0));
  set_encumbrance(
    to_int((percent * to_float(query_encumbrance()))) / 100);  // must be last!
}

void liquid_drunken() {
  mixed msg;
  message(
    funcall(query_drunken_message() ||
            ({({ M_ROOM, environment(this_player()), M_PL_THE, M_PL_VERB,
                 "drink", " some of ", M_ME_THE, "." })})));
  if ((msg = query_taste()))
    send_message(({ M_WRITE, msg[0..<2] }));
}

void liquid_drunken_all() {
  mixed msg;
  message(
    funcall(query_drunken_all_message() ||
            ({({ M_ROOM, environment(this_player()),
                 M_PL_THE, M_PL_VERB, "drink", M_ME_THE, "." })})));
  if ((msg = query_taste()))
    send_message(({ M_WRITE, msg[0..<2] }));
}

void liquid_slurped() {
  mixed msg;
  message(
    funcall(query_slurped_message() ||
            ({({ M_ROOM, environment(this_player()), M_PL_THE, M_PL_VERB,
                 "slurp", " some of ", M_ME_THE, "." })})));
  if ((msg = query_taste()))
    send_message(({ M_WRITE, msg[0..<2] }));
}

void liquid_slurped_all() {
  mixed msg;
  message(
    funcall(query_slurped_all_message() ||
            ({({ M_ROOM, environment(this_player()),
                 M_PL_THE, M_PL_VERB, "slurp", M_ME_THE, "." })})));
  if ((msg = query_taste()))
    send_message(({ M_WRITE, msg[0..<2] }));
}

void liquid_sipped() {
  mixed msg;
  message(
    funcall(query_sipped_message() ||
            ({({ M_ROOM, environment(this_player()),
                 M_PL_THE, M_PL_VERB, "sip", M_ME_THE, "." })})));
  if ((msg = query_taste()))
    send_message(({ M_WRITE, msg[0..<2] }));
}

static void check_bottle(mapping e) {
  if (!e[E_FROM])
    return;
  if (sizeof(filter_objects(all_inventory(e[E_FROM]), "query_encumbrance"))) {
    send_message(({ M_TARGETS, e[E_AGENT], "You recognize something left in ",
                    M_THE, M_OBJECT, e[E_FROM], "." }));
    //DEBUG_POINT("coogan", ({ e }));
    send_event(e[E_SUCCESS,1][E_TYPE],
               e[E_SUCCESS,1],
               e[E_SUCCESS,1][E_RECEIVERS]);
  }
}

object copy_liquid() {
  object new, p, p_new;
  string *variables;
  int i;
  new = liquid::copy_liquid();
  new->set_name(query_real_name());
  new->set_short(query_real_short());
  new->set_long(query_real_long());
  new->set_encumbrance(item::query_encumbrance());
  new->set_id(query_real_id());
  new->set_taste(query_real_taste());
  new->set_smell(query_real_smell());
  new->set_touch(query_real_touch());
  new->set_portion(query_portion());
  new->set_colour(query_colour());
  new->set_dirty(query_dirty());
#if 1  // Coogan, 13-Jan-01
  variables = decay::query_persistent_variables();
  for (i=sizeof(variables); i-->0; )
    call_other(new,"set_" + variables[i],
               call_other(this_object(),"query_" + variables[i]));
#else
  new->set_decay_rate(query_decay_rate());
  new->set_decay_stages(query_decay_stages());
  new->set_decay_descriptions(query_decay_descriptions());
#endif
#if 1  // Coogan, 16-May-01
  variables = liquid::query_persistent_variables();
  for (i=sizeof(variables); i-->0; )
    call_other(new,"set_" + variables[i],
               call_other(this_object(),"query_" + variables[i]));
#else
  new->set_drunken_message(query_drunken_message());
  new->set_drunken_all_message(query_drunken_all_message());
  new->set_slurped_message(query_slurped_message());
  new->set_slurped_all_message(query_slurped_all_message());
  new->set_sipped_message(query_sipped_message());
  new->set_drink_func(query_drink_func());
  new->set_drink_func_name(query_drink_func_name());
#endif
  for (p = first_inventory(); p; p = next_inventory(p))
    if (p->query_property(P_POISON)) {
      p_new = clone_object(load_name(p));
      p_new->set_poison_type(p->query_poison_type());
      p_new->set_poison_rate(p->query_poison_rate());
      p_new->set_poison_speed(p->query_poison_speed());
      p_new->set_poison_drain_rate(p->query_poison_drain_rate());
      p_new->set_poison_drain_speed(p->query_poison_drain_speed());
      p_new->set_poison_time_left(p->query_poison_time_left());
      move_object(p_new, new);
    }
  return new;
}

void receive_move_event(mapping e, string type, int prio) {
  int h;
  object new;

  if (e[E_TO] == environment())  // someone comes to us?
    if (!random(e[E_AGENT]->query_dex() || 10)) {
      send_message(({ M_THE, e[E_AGENT], M_VERB, "step", e[E_AGENT],
                      " into ", M_ME_THE, "." }));
      set_tracemakers(query_tracemakers() + ([ e[E_AGENT] ]));
    }
  else if (member(query_tracemakers(), e[E_AGENT]) &&
           e[E_FROM] == environment()) {
    if (stringp(e[E_DIR]))
      set_traces(query_traces() + ([ e[E_DIR]: e[E_AGENT]->query_name() ]));
    set_tracemakers(query_tracemakers() - ([e[E_AGENT]]));
    // the leaver takes some part of us with him...
    if (h = find_extreme(({ query_encumbrance() / 10,
                            query_portion() / 2 }), #'< )) {
      // let's re-scale this liquid to 100 percent
      renew_liquid(100);
      // now we 'copy' all values to get 2 identical liquids
      new = copy_liquid();
      // we re-scale both liquids to their encumbrances
      h = 100 * h / item::query_encumbrance();  // h in percent
      renew_liquid(100 - h);
      new->renew_liquid(h);
      move_object(new, e[E_TO]);
    }
  }
}

void receive_open_event(mapping e) {
  if (!environment() || e[E_SUCCESS] == 0 || e[E_TARGET] != environment())
    return;
  start_drying_away();
}

void receive_close_event(mapping e) {
  if (!environment() || e[E_SUCCESS] == 0 || e[E_TARGET] != environment())
    return;
  stop_drying_away();
  renew_liquid(100);
}

void receive_drink_event(mapping e, string action, int prio) {
  status o;
  int enc;
  mixed m, p;

  if (e[E_TARGET] != this_object())  // we are not mentioned
    return;
  if (prio == EPRIO_CANCEL) {
    mapping de, oe, ce;
    if (!e[E_FROM])  // no bottle to open ...
      return;
    if ((o = e[E_FROM]->query_open()))  // bottle is already open
      return;
    if (!e[E_SUCCESS])  // somebody other already changed the event
      return;
    de = copy(e);
    de-= ([ E_SENDER ]);
    de-= ([ E_CANCELLED ]);
    de-= ([ E_SUCCESS ]);
    oe = ([
            E_AGENT  : e[E_AGENT]; e[E_AGENT]->query_name(),
            E_TARGET : e[E_FROM] ; e[E_FROM, 1],
            E_SUCCESS: 1         ; 0,
         ]);
    ce = deep_copy(oe);
    ce += ([ E_TYPE    : "close"; 0  ]);
    de += ([ E_SUCCESS : 1      ; ce ]);  // prepare send of close event
    oe[E_SUCCESS,1] = de;                 // prepare re-send of drink event
    e[E_SUCCESS] = 0;
    cancel_event();
    send_event("open", oe, e[E_RECEIVERS]);
    return;
  }
  if (e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  if (e[E_SUCCESS] == 0)
    return;
  if (e[E_ALCOHOL_RATE]) {
    if (!e[E_AGENT]->test_drink_alcohol(e[E_ALCOHOL_RATE])) {
      e[E_SUCCESS] = 0;
      if (mappingp(e[E_SUCCESS, 1]))
        check_bottle(e);
      return;
    }
  }
  else
    if (e[E_BODY_HEALING_RATE])
      if (!e[E_AGENT]->test_drink_soft(e[E_BODY_HEALING_RATE])) {
        e[E_SUCCESS] = 0;
        if (mappingp(e[E_SUCCESS, 1]))
          check_bottle(e);
        return;
      }

  m = query_encumbrance();
  if (e[E_ALCOHOL_RATE] >= 12 && e[E_AGENT]->query_level() < 10) {
    message(({({ M_WRITE, "You sputter liquid all over the room." }),
              ({ M_SAY, M_THE, e[E_AGENT], M_VERB, "try", e[E_AGENT], M_THE }) +
                 (e[E_FROM] ? ({ e[E_FROM] }) : ({ M_ME })) +
                 ({ " but ", M_VERB, "cough", e[E_AGENT], " and ",
                 M_VERB, "sputter", e[E_AGENT], M_PRONOUN }) +
                 (e[E_FROM] ? ({ e[E_FROM] }) : ({ M_ME })) +
                 ({ " all over you." })}));
    e[E_TARGET]->renew_liquid(100 * (m - e[E_AMOUNT]) / m);
    e[E_SUCCESS] = 0;
    if (mappingp(e[E_SUCCESS,1]))
      check_bottle(e);
    return;
  }

  if (!e[E_ALCOHOL_RATE] &&
      e[E_BODY_HEALING_RATE] >= 8 && e[E_AGENT]->query_level() < 5) {
    message(({ ({ M_WRITE, "You throw it all up." }),
               ({ M_SAY, M_THE, e[E_AGENT], M_VERB, "try", e[E_AGENT], " to ",
                  e[E_TYPE, 1], M_THE }) +
                  (e[E_FROM] ? ({ e[E_FROM] }) : ({ M_ME })) +
                  ({ " but ", M_VERB, "throw", e[E_AGENT], " up." })}));
    e[E_TARGET]->renew_liquid(100 * (m - e[E_AMOUNT]) / m);
    e[E_SUCCESS] = 0;
    if (mappingp(e[E_SUCCESS,1]))
      check_bottle(e);
    return;
  }

  if (!e[E_ALCOHOL_RATE] &&
      e[E_BODY_HEALING_RATE] > e[E_AGENT]->query_level() * 5) {
    message(({({ M_WRITE, "This is much to much for you to drink! "
                 "You drool most of it on the ground." }),
              ({ M_SAY, M_THE, e[E_AGENT], M_VERB, "try", e[E_AGENT], " to ",
                 e[E_TYPE, 1], M_THE }) +
                 (e[E_FROM] ? ({ e[E_FROM] }) : ({ M_ME })) +
                 ({ " but ", M_VERB, "drool", e[E_AGENT],
                 " most of ", M_PRONOUN, e[E_TARGET], " on the ground." })}));
    e[E_TARGET]->renew_liquid(100 * (m - e[E_AMOUNT]) / m);
    e[E_SUCCESS] = 0;
    if (mappingp(e[E_SUCCESS,1]))
      check_bottle(e);
    return;
  }

  switch (e[E_TYPE, 1]) {
    case "drink":
      if (e[E_AMOUNT] >= m && environment(e[E_TARGET]))
        with_player(e[E_AGENT], #'liquid_drunken_all);
      else
        with_player(e[E_AGENT], #'liquid_drunken);
      break;
    case "slurp":
      if (e[E_AMOUNT] >= m && environment(e[E_TARGET]))
        with_player(e[E_AGENT], #'liquid_slurped_all);
      else
        with_player(e[E_AGENT], #'liquid_slurped);
      break;
    case "sip":
      with_player(e[E_AGENT], #'liquid_sipped);
      break;
  }

#if 1  // Coogan, 13-Jan-01
  if (e[E_ALCOHOL_RATE]) {
    e[E_AGENT]->drink_alcohol(e[E_ALCOHOL_RATE]);
    e[E_AGENT]->reduce_hit_point(-e[E_BODY_HEALING_RATE]);
    e[E_AGENT]->restore_spell_points(e[E_MIND_HEALING_RATE]);
  }
  else if (e[E_BODY_HEALING_RATE] || e[E_MIND_HEALING_RATE]) {
    e[E_AGENT]->drink_soft(e[E_BODY_HEALING_RATE]);
    e[E_AGENT]->reduce_hit_point(-e[E_BODY_HEALING_RATE]);
    e[E_AGENT]->restore_spell_points(e[E_MIND_HEALING_RATE]);
  }
  else {  // e.g. a dummy liquid without healing, Coogan, 29-Aug-2004
    e[E_AGENT]->add_soaked(5);
  }
#else
  if (e[E_ALCOHOL_RATE]) {
    e[E_AGENT]->drink_alcohol(e[E_ALCOHOL_RATE]);
    e[E_AGENT]->heal_self(e[E_HEALING_RATE] || e[E_ALCOHOL_RATE]);
  }
  else if (e[E_HEALING_RATE]) {
    e[E_AGENT]->drink_soft(e[E_HEALING_RATE]);
    e[E_AGENT]->(e[E_HEALING_RATE]);
  }
#endif

  drink_action(e[E_AGENT], e[E_AMOUNT]);  // Coogan, 16-May-01

  enc = query_encumbrance();
  if (enc <= e[E_AMOUNT])
    m = this_object();
  else {
    m = copy_liquid();
    renew_liquid(100 * e[E_AMOUNT] / enc);
    m->renew_liquid(100 * (enc - e[E_AMOUNT]) / enc);
  }
  while (first_inventory())                // poison!
    move_object(first_inventory(), e[E_AGENT]);
  set_consumed();
  move_object(this_object(), e[E_AGENT]);
  call_out(#'destruct, 2, this_object());  // give other listeners the
                                           // possibility to react on the event
  if (m != this_object() && member(e, E_FROM))  // added check for E_FROM,
    move_object(m, e[E_FROM]);                  // Coogan, 14-Aug-2006
  if (mappingp(e[E_SUCCESS,1]))
    check_bottle(e);
  return;
}

varargs status consume_liquid(int howmuch, string action) {
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
         E_TYPE              : "drink"      ; action || "drink",
         E_TARGET            : this_object(); query_real_name(),
         E_AGENT             : this_player(); this_player()->query_name(),
         E_RECIPIENT         : this_player(); this_player()->query_name(),
         E_ALCOHOL_RATE      : a            ; 0,
         E_BODY_HEALING_RATE : b            ; 0,
         E_MIND_HEALING_RATE : m            ; 0,
         E_AMOUNT            : howmuch      ; 0,
         E_SUCCESS           : 1            ; 0,
      ]);
  if (query_invitro())
    e += ([ E_FROM : environment(); describe(environment(), ARTICLE_NONE) ]);
  send_event("drink", e, ({ environment(this_player()), e[E_TARGET] }));
  return e[E_SUCCESS];
}

string query_dirty_state_description(status in_output) {
  switch (query_dirty()) {
  default:
    raise_error("Illegal value.\n");
  case 0:
    if (in_output)
      return 0;
    else
      return "clean";
  case 1:
    return "dirty";
  case 2:
    return "very dirty";
  case 3:  // complete mixture
    return 0;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 27-Mar-2011
}

status mix_liquid(object other_liquid) {
  mixed h;
  int enc, own_enc;

  if (!other_liquid->query_property(P_LIQUID))
    raise_error("Bad argument to mix_liquid().\n");
  if (previous_object() == other_liquid) {
    renew_liquid(100);
    other_liquid->renew_liquid(100);
  }
  enc = other_liquid->query_encumbrance();
  own_enc = query_encumbrance();
//DEBUG_POINT("coogan", ({ "mischen von", this_object(), other_liquid,
//                         own_enc, enc }));
  switch (enc * 100 / (enc + own_enc)) {
  default:
    raise_error("Illegal value.\n");

  case 0..14:  // other_liquid is much less than we are
    break;
  case 15..34:  // other_liquid is less than we are, but not much
    // now it's gettin' dirty ;-)
    // hmm ... I mixed beer with beer, and all I got was a completely mixed
    // dirty beer?? *puzzle*, Coogan.

    if (query_real_name() == other_liquid->query_real_name()) {
      switch (query_dirty()) {
        // it's mixed with the same liquid, so only recalibrate the dirt
        // this_liquid  | 0 0 0 0  1 1 1 1  2 2 2 2  3 3 3 3
        // other_liquid | 0 1 2 3  0 1 2 3  0 1 2 3  0 1 2 3
        // -------------------------------------------------
        // result       | 0 0 0 1  1 1 1 2  1 2 2 2  2 3 3 3
        case 0: set_dirty(other_liquid->query_dirty() == 3);       break;
        case 1: set_dirty((other_liquid->query_dirty() == 3) + 1); break;
        case 2: set_dirty(2 - (other_liquid->query_dirty() == 0)); break;
        case 3: set_dirty(3 - (other_liquid->query_dirty() == 0)); break;
      }
      if (query_dirty())
        delete_all_drink_messages();
      break;
    }
    // we delete all messages once set for a pure liquid
    delete_all_drink_messages();
    if (query_dirty() == 3)  // already complete mixture?
      break;  // continue with int-stuff below
    else
      if (query_dirty() == 2)  // already very dirty?
        ;  // fall into case below
      else
        if (query_dirty() == 1)  // already dirty?
          {
          set_dirty(2);
          break;
          }
        else
      {  // not yet dirty
      set_dirty(1);
      if (query_real_smell() != other_liquid->query_real_smell())
        if (query_real_smell())
          set_smell("strangely " + query_real_smell());
        else
          set_smell("weakly " + other_liquid->query_real_smell());
      if (query_real_taste() != other_liquid->query_real_taste())
        if (query_real_taste())
          set_taste("strangely " + query_real_taste());
        else
          set_taste("weakly " + other_liquid->query_real_taste());
      break;
      }

  case 35..65:  // nearly the same quantities
    if (query_real_name() == other_liquid->query_real_name()) {
      set_dirty((find_extreme(({ query_dirty(), other_liquid->query_dirty() }),
                              #'<) || 1) - 1);
      break;
    }
    // perhaps we are getting mixed with water? So we are cleaned up a bit.
    if (query_real_name() == "water" && !query_dirty())
      set_dirty((other_liquid->query_dirty() || 1) - 1);
    else if (other_liquid->query_real_name() == "water" &&
             !other_liquid->query_dirty())
      set_dirty((query_dirty() || 1) - 1);
    else
      set_dirty(3);
    if (other_liquid->query_real_name() != query_real_name() ||
        query_dirty() || other_liquid->query_dirty()) {
      set_name("liquid");
      delete_all_drink_messages();
    }
    if (other_liquid->query_real_short() != query_real_short())
      set_short("a liquid");
    if (other_liquid->query_real_long() != query_real_long())
      set_long("This seems to be a mixture of several different liquids.\n");
    if (sizeof(query_real_id()) !=
          sizeof(other_liquid->query_real_id() & query_real_id()))
      set_id(({ "liquid", "mixed liquid" }));
    h = other_liquid->query_real_smell();
    if (h != query_real_smell())
      if (!h || !query_real_smell())
        set_smell(h || query_real_smell());
      else if (enc > own_enc)
        set_smell(h + "-" + query_real_smell());
      else
        set_smell(query_real_smell() + "-" + h);
    if (strlen(query_real_smell()) > 20)
      set_smell("strange");
    h = other_liquid->query_real_taste();
    if (h != query_real_taste())
      if (!h || !query_real_taste())
        set_taste(h || query_real_taste());
      else if (enc > own_enc)
        set_taste(h + "-" + query_real_taste());
      else
        set_taste(query_real_taste() + "-" + h);
    if (strlen(query_real_taste()) > 20)
      set_taste("strange");
    break;

  case 66..100:  // other_liquid is more than we are, maybe much
    other_liquid->mix_liquid(this_object());
    return 0;
  }
  set_colour(LIB_COLOURS->mix_colours(({ query_colour(),
                                         own_enc,
                                         other_liquid->query_colour(),
                                         enc })));
  set_portion((query_portion() * own_enc +
               other_liquid->query_portion() * enc) / (enc + own_enc));
//  DEBUG_POINT("coogan",({ query_drying_rate(),other_liquid->query_drying_rate(),
//                          find_call_out("dry_away") }));
  liquid::mix_liquid(other_liquid);
//  DEBUG_POINT("coogan", ({ query_drying_rate(), find_call_out("dry_away") }));
  set_encumbrance(own_enc + enc);
  destruct(other_liquid);
//  DEBUG_POINT("coogan", ({ query_encumbrance() }));
  return 1;
}

private string get_special_id() {
  if (query_encumbrance() <= DROPS)
    return "drops";
  else if (query_encumbrance() <= PUDDLE)
    return "puddle";
  else
    return "pool";
}

status id(string str) {
  return item::id(str) || !query_invitro() && get_special_id() == str;
}

int query_gender() {
  if (query_invitro())
    return item::query_gender();
  else if (query_encumbrance() <= DROPS)
    return GND_PLURAL;
  else
    return GND_NEUTER;
}

string query_name() {
  if (query_invitro())
    return query_real_name();
  else if (query_encumbrance() <= DROPS)
    return "drops of " + describe(query_real_name(), ARTICLE_NONE);
  else if (query_encumbrance() <= PUDDLE)
    return "puddle of " + describe(query_real_name(), ARTICLE_NONE);
  else
    return "pool of " + describe(query_real_name(), ARTICLE_NONE);
}

string query_short() {
  if (query_invitro()) {
#if 1
    return describe((query_colour()
                     ? LIB_COLOURS->get_colour_name(query_colour()) + " "
                     : "") + describe(query_real_short(), ARTICLE_NONE),
                    ARTICLE_A);
#else
    return query_real_short();
#endif
  }
  else if (query_encumbrance() <= DROPS)
    return "a few drops of " + describe(query_real_short(), ARTICLE_NONE);
  else if (query_encumbrance() <= PUDDLE)
    return "a puddle of " + describe(query_real_short(), ARTICLE_NONE);
  else
    return "a pool of " + describe(query_real_short(), ARTICLE_NONE);
}

varargs string query_long(string str) {
  mixed s,h;

  if (query_invitro())
    return query_real_long();
  else if (query_encumbrance() <= DROPS)
    s = "These few drops of " +
        (query_colour()
          ? LIB_COLOURS->get_colour_name(query_colour()) + " " : "") +
        describe(query_real_short(), ARTICLE_NONE) +
        " are sprinkled on the ground.";
  else if (query_encumbrance() <= PUDDLE)
    s = "This puddle of " +
        (query_colour()
          ? LIB_COLOURS->get_colour_name(query_colour()) + " " : "") +
        describe(query_real_short(), ARTICLE_NONE) +
        " has formed on the ground.";
  else
    s = "This pool of " +
        (query_colour()
          ? LIB_COLOURS->get_colour_name(query_colour()) + " " : "") +
        describe(query_real_short(), ARTICLE_NONE) +
        " has formed on the ground.";
  switch (query_dirty()) {
  default:
    raise_error("Illegal value.\n");
  case 0:
  case 3:
    break;
  case 1:
    s += (query_plural()
          ? " They seem to be messy a bit."
          : " It seems to be messy a bit.");
    break;
  case 2:
    s += (query_plural()
          ? " They are very dirty and you hardly can identify the liquid."
          : " It is very dirty and you hardly can identify the liquid.");
  }

  if (sizeof(h = m_indices(query_traces())))
    if (sizeof(h) > 1)
      s += " Traces are leading " + make_list(h) + ".";
    else
      s += " A trace is leading " + make_list(h) + ".";
  return s + "\n";
}

string short() {
  if (!query_property(P_STATE_DESCRIPTION) && !random(10))
    log_file("state_description", load_name(this_object())+"\n");
  return query_short();
}

varargs string long(string str) {
  return query_long(str);
}

void configure() {
  if (!clonep())
    return;
  item::configure();
  set_traces(([:1]));  // added :1, Coogan, 28-Aug-2003
  set_tracemakers(([:0]));  // added :0, Coogan, 28-Aug-2003
  set_persistence(__FILE__, PER_KEEP_VARS, ({
    ({ "name",  "set_name",  "query_real_name" }),
    ({ "short", "set_short", "query_real_short" }),
    ({ "long",  "set_long",  "query_real_long" }),
    ({ "id",    "set_id",    "query_real_id" }),
    ({ "taste", "set_taste", "query_real_taste" }),
    ({ "smell", "set_smell", "query_real_smell" })
    }) +
    decay::query_persistent_variables() +       // Coogan, 13-Jan-01
#if 1  // Coogan, 16-May-01
    liquid::query_persistent_variables() +      // Coogan, 16-May-01
#else
    ({
    "drink_func", "drink_func_name",
    "drunken_all_message", "drunken_message",
    "sipped_message",
    "slurped_all_message", "slurped_message", }) +
#endif
    ({
    "drying_rate", "alcohol_rate",
    "colour", "dirty", "portion",
    }));
#if 0  // Coogan, 11-Jan-01
  set_name("liquid");
#endif
  set_short("a non-descript liquid");
  set_long(lambda(0, ({ #'+,
                        ({ #'capitalize, ({ #'short }) }),
                        ".\n" })));
  set_id(({ "liquid", query_real_short() }));
  set_encumbrance(1000);
  set_property(P_LIQUID);
  set_property(P_NOT_PORTABLE);
  set_decay_stages(7);
  set_decay_rate(10000 + to_int(1000.0 * "basic/math"->gauss_random()));
  // no decay descriptions, because we don't use a decay state description
  add_to_property(P_STATE_DESCRIPTION, ({ 0,"query_dirty_state_description" }));
  add_action_error_message("step", "Step into what?\n");
  add_action_error_message("jump", "Jump into what?\n");
  listen_event("move",  EPRIO_NOTICE, #'receive_move_event);
  listen_event("open",  EPRIO_NOTICE, #'receive_open_event);
  listen_event("close", EPRIO_NOTICE, #'receive_close_event);
  listen_event("drink", EPRIO_HANDLE, #'receive_drink_event);
  listen_event("drink", EPRIO_CANCEL, #'receive_drink_event);
}

void init() {
  item::init();  // Coogan, 16-May-01
  if (query_encumbrance() <= 0) {
    while (first_inventory())
      destruct(first_inventory());
    destruct(this_object());
    return;
  }
  add_action_rule("step into "G_OBJECT, "step");
  add_action_rule("jump into "G_OBJECT, "jump");
}

status do_action(string verb,mapping args) {
  switch (verb) {
  case "jump": // fall through
  case "step":
    if (args[G_OBJECT] == this_object()) {
      send_message(({ M_PL_THE, M_PL_VERB, verb, " into ", M_ME_THE, "." }));
      if (verb == "jump")
        send_message(({ "SPLASH!" }));
      set_tracemakers(m_add(query_tracemakers(), this_player()));
      return 1;
    }
    return 0;
  }
  // default:
  return 0;
}

void notify_move(object from, object to) {
  liquid::notify_move(from, to);
}

void notify_destruct() {
  unlisten_event("move",  EPRIO_NOTICE, #'receive_move_event);
  unlisten_event("open",  EPRIO_NOTICE, #'receive_open_event);
  unlisten_event("close", EPRIO_NOTICE, #'receive_close_event);
  unlisten_event("drink", EPRIO_HANDLE, #'receive_drink_event);
  unlisten_event("drink", EPRIO_CANCEL, #'receive_drink_event);
  liquid::notify_destruct();
}

status drop(status silently) {
  return !query_short();
}

