/*
 * /basic/holdable.c
 *
 * An interface for objects that can be held and wielded by other objects
 * This interface depends on basic/hold.c
 */

#include <closures.h>
#include <global_commands.h>
#include <grammar.h>
#include <event.h>
#include <action.h>
#include <prop/item.h>
#include <message.h>

string query_name();

// We are recording who is holding/wielding us 
// The 'where' is only given for the case that we want to delegate this
// functionality (like a compound that delegates it to one of its components
// that is _really_ held instead of the whole compound)

private static mapping held_by;  // (holder -> (handname -> handob) x wielding)

// The arguments frequently used in this file mean the following:
// 'who' -- who is holding us
// 'location' -- on which part of ours

varargs status query_held_by(object who, string location, mixed with);
varargs status query_wielded_by(object who);

status query_held();
status query_wielded();

varargs object *get_holders(string location);
varargs object *get_wielders();

object *get_holding_parts(object who, string location);
varargs string get_held_location(object who, string location, mixed with);

private mapping get_held_by() {
  if (!held_by)
    return held_by = m_allocate(1,2);
  else
    return m_delete(held_by,0);
}

varargs object *get_holders(string location) {
  return m_indices(get_held_by());
}

varargs object *get_wielders() {
  return filter(get_holders(),#'query_wielded_by);
}

varargs status query_held_by(object who, string location, mixed with) {
  if (!who)
    return sizeof(get_held_by()) > 0;
  else if (!with)
    return sizeof(get_held_by()[who]);
  else {
    if (objectp(with))
      with = with->query_real_name() || object_name(with);
    return query_held_by(who) && member(get_held_by()[who],with);
  }
}

status query_held() {
  return query_held_by();
}

varargs status query_wielded_by(object who) {
  if (!who)
    return sizeof(get_wielders());
  else 
    return
      query_held_by(who) && get_held_by()[who,1];
}

status query_wielded() {
  return query_wielded_by();
}

private object get_holding_with(mixed with, object who) {
  if (objectp(with))
    with = with->query_real_name() || object_name(with);
  if (member(get_held_by()[who],with) && !held_by[who][with])
    held_by[who][with] = who->get_holding_part(with);
  return held_by[who][with];
}

// if the holder isn't holding this, return 0
varargs object *get_holding_parts(object who, string location) {
  if (who && query_held_by(who))
    return m_values(map_indices(get_held_by()[who],#'get_holding_with,who));
  else
    return ({});
}

string get_held_location(object who, string location, mixed with) {
  if (query_held_by(who,location,with))
    return query_name();
}

void notify_action_drop(mapping e) {
  int i;
  mixed *parts;
  mapping action;

  for (i = sizeof(parts = get_holding_parts(e[E_AGENT])); i--; )
    if (action = with_player(e[E_AGENT],#'call_other,
                             ({parts[i],"build_action",
                               "let_go",
                               ([A_G_TARGET: this_object();
                                             query_name()]),
                               A_MODE_FAST})))
      parts[i]->schedule_action(action);
}

status notify_action_take(mapping e) {
  int i;
  mixed *parts;
  mapping action;

  if (e[E_AGENT] != environment() &&
      query_held_by(environment()) &&
      query_held_by(e[E_AGENT]) &&
      environment()->is_offered(this_object(),e[E_AGENT])) {
    for (i = sizeof(parts = get_holding_parts(environment())); i--; )
      if (action = with_player(environment(),#'call_other,
                               ({parts[i],"build_action",
                                 "let_go",
                                 ([A_G_TARGET: this_object();
                                               query_name()]),
                                 A_MODE_FAST})))
        parts[i]->schedule_action(action);
  } else if (e[E_AGENT] == environment() &&
             sizeof(parts = get_holding_parts(environment())) > 1 &&
             member(parts,e[E_TOOL]) >= 0) {
    for (i = sizeof(parts); i--; )
      if (parts[i] != e[E_TOOL] &&
          (action = with_player(environment(),#'call_other,
                                ({parts[i],"build_action",
                                "let_go",
                                ([A_G_TARGET: this_object();
                                              query_name()]),
                                A_MODE_FAST}))))
        parts[i]->schedule_action(action);
  }
  return 1;
}

status drop(status silently) {
  /*
  if (query_wielded_by(environment())) {
    if (!silently && this_player() == environment())
      send_message(({M_WRITE, "You should unwield ",
                     M_OBJECT,M_ME_THE," first."}));
    return 1;
  }
  */
  return 0;
}

status prevent_drop() {
  return
    (environment() &&
     (drop(1) ||
      query_held_by(environment()) ||
      environment()->query_property(P_SURFACE) ||
      environment()->query_property(P_CONTAINER) ||
      !environment(environment())));
}

void drop_item() {
  if (living(environment()))
    with_player(environment(),#'call_other,
                ({COMMANDS_MOVE,
                  "do_action",
                  "drop_all",
                  ([G_ALL: ({this_object()});
                           ({query_name(),1})])}));
}

status prevent_hold(object who, string location, mixed with) { return 0; }
status prevent_let_go(object who, string location, mixed with) { return 0; }
status prevent_wield(object who) { return 0; }

void notify_wield(object who) {
  get_held_by();
  held_by[who,1] = 1;
}

status notify_action_wield(mapping a) {
  if (a[E_SUCCESS]) {
    send_message(({a[E_AGENT],M_VERB,"wield",a[E_AGENT],
                   M_OBJECT,M_THE,a[E_TARGET],"."}));
    notify_wield(a[E_AGENT]);
    return 1;
  }
}

void notify_unwield(object who) {
  if (member(get_held_by(),who))
    held_by[who,1] = 0;
}

status notify_action_unwield(mapping a) {
  if (a[E_SUCCESS]) {
    notify_unwield(a[E_AGENT]);
    send_message(({a[E_AGENT]," no longer ",M_VERB,"wield",a[E_AGENT],
                   M_OBJECT,M_THE,a[E_TARGET],"."}));
    return 1;
  }
}

void notify_hold(object who, string location, mixed with) {
  if (!get_held_by()[who])
    held_by[who] = ([]);
  if (objectp(with))
    held_by[who] += ([ with->query_real_name() || object_name(with) : with ]);
  else
    held_by[who] += ([ with : 0 ]);
}

// we can only be let go, if we're held
void notify_let_go(object who, string location, mixed with) {
  mapping h;
  
  get_held_by();
  if (objectp(with))
    with = with->query_real_name() || object_name(with);
  if (h = held_by[who])
    m_delete(h,with);
  if (!query_held_by(who)) {
    notify_unwield(who);
    m_delete(held_by,who);
  }
  if (environment() == who && !prevent_drop())
    drop_item();
}

string query_hold_description(status in_output) {
  if (query_wielded_by(environment())) {
    if (in_output)
      return "wielded";
    else
      return "wielded\\>|\\<held";
  } else if (query_held_by(environment())) {
    return "held";
  } else if (!in_output) {
    return
      "not wielded\\>|\\<unwielded\\>|\\<not held";
  }
}

string query_side_description(status in_output) {
  int i;
  mixed h, result;

  if (!in_output && query_held_by(environment())) {
    h = get_holding_parts(environment());
    result = ({});
    for (i = sizeof(h); i--; )
      if (h[i]->id("hand"))
        if (h[i]->has_position("right"))
          result += ({"right"});
        else if (h[i]->has_position("left"))
          result += ({"left"});
    if (sizeof(result)) {
      return implode(result,"\\>|\\<");
    }
  }
}

