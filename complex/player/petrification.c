#include <filter.h>
#include <event.h>
#include <message.h>
#include <limits.h>
#include <gender.h>
#include <time_units.h>

inherit "basic/curse";

private static string *filters = ({ F_ID,
                                    F_ID_CLOSURE,
                                    F_GENDER,
                                    F_NAME,
                                    F_SHORT,
                                    F_LONG, 
                                    F_NO_ARTICLE });

private status linkdead_mark;

void receive_depetrify_event(mapping e) {
  if (e[E_AGENT] == environment()) {
    // message added by Coogan, 11-May-98
    if (e[E_AGENT]->short())
      send_message(({ M_ROOM, environment(e[E_AGENT]), M_EXCLUDE, e[E_AGENT],
                      M_THE, M_FULL, e[E_AGENT], " suddenly ", M_VERB, "come",
                      e[E_AGENT], " alive!" }));
    destruct(this_object());
  }
}

void apply_curse(object who) {
  if (!living(who))
    self_destruct();
  else
    reshape_with_messages(who,lambda(0,({ (#'map),
                                          quote(filters),"add_filter",who,
                                          FPRIO_PETRIFICATION })),
                          ("You suddenly turn into stone but you are still"
                           " invisible.\n"));
}

void remove_curse(object who) {
  if (!linkdead_mark) // Chameloid, 9-May-98
    reshape_with_messages(who,lambda(0,({ (#'map),quote(filters),
                                          "remove_filter",who })),
                          ("You suddenly turn alive again but you are still"
                           " invisible.\n"));
}

mixed do_filter(string func,mixed arg) {
  string vis_name;
  switch (func) {
  case F_ID:
    return arg + ({ "statue","stone statue" });
  case F_ID_CLOSURE:
    // return a closure (one argument) which returns true if the closure
    // arg returns true for its argument or for its argument without a
    // leading "stone statue of " or "statue of ".
    return lambda(({ 'x }),
                  ({ (#'funcall),
                     arg,
                     ({ (#'regreplace),'x,"^(stone |)statue of ","",1 }) }));
  case F_GENDER:
    return GND_NEUTER;  // statues are neuter
  case F_NAME:
#if 0  // 1: "Alfe's stone statue", 0: "statue"
    return (environment()->call_with_limited_filters(#'describe,
                                                     INT_MIN,
                                                     FPRIO_PETRIFICATION-1,
                                                     environment(),0,0,0,1) +
            " stone statue");
#else
    return "statue";
#endif
  case F_SHORT:
#if 1
    return ("a stone statue of " +
            environment()->call_with_limited_filters(#'call_other,
                                                     INT_MIN,
                                                     FPRIO_PETRIFICATION-1,
                                                     environment(),
                                                     "query_name"));
#else
    return "a stone statue";
#endif
  case F_LONG:
    return ("A stone statue of " +
            environment()->call_with_limited_filters(#'call_other,
                                                     INT_MIN,
                                                     FPRIO_PETRIFICATION-1,
                                                     environment(),"short") +
            ".\n"
            "You wonder when it will come alive again.\n");
  case F_NO_ARTICLE:
    return 0;
  default: 
    return arg;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 27-Mar-2011
}

void set_linkdead_mark() {
  listen_event("depetrify",-500,#'receive_depetrify_event);
  listen_event("login", -500, #'receive_depetrify_event);  // Coogan, 09-Nov-99
  linkdead_mark = 1;
  if (previous_object() && previous_object()->query_real_name() == "aife")
    set_curse_duration(10);
  else
    set_curse_duration(30 * ONE_MINUTE);  // self destruct in 30 minutes,
                                          // log the player out then
}

void self_destruct() {
  if (linkdead_mark && query_once_interactive(environment())) {
#ifdef TUBMUD  // Coogan, 10-Oct-2004
    object br;
#include "/domains/momu/sys/momu.h"
    if ((br = present_clone(MOMUBRAIN, environment()))) {
      with_player(environment(), #'call_other, ({ br, "do_action", "quit" }));
        // this will bring the player back to the mud
        // ( ~70k eval costs for full equip and 30 autoloads)
        // afterwards we can continue logging him out.
      if (!environment()->query_saving())       // make his real equip
        environment()->save();                  // into the persistence files
    }
#endif
    if (environment()->query_saving())  // is this player still saving?
      return call_out(#'self_destruct,10);
    else { // not saving, fine. go on.
      if (environment() && environment()->short()) // Chameloid, 9-May-98
        send_message(({ M_FULL,M_THE,environment(),
                        M_VERB,"wither",environment()," to dust." }));
      environment()->quit();
    }
  }
  if (this_object()) // not destructed yet?, Chameloid, 1-May-98
    curse::self_destruct();  // call super class (destruct ourself)
}

mixed *query_auto_load() {
  return !linkdead_mark && curse::query_auto_load();
}

mixed get_state() { return -1; } // Chameloid, 27-Apr-98

// added this function and init() to fix that players who are disconnected
// for a very short time stay as statues, Coogan, 28-Mar-99
int do_depetrify(string str) {
  if (environment() &&
      interactive(environment()) &&
      this_player() == environment())
    remove_curse(environment());
  return 0;
}

#if 0
void init() {
  add_action("do_depetrify", "", 1);
}
#endif

status prevent_move(object from, mixed to) {  // Coogan, 14-Jun-99
  if (from && query_once_interactive(from))
    return 1;
  return 0;
}

