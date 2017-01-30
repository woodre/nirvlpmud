/*
 * defender.c -- written by Ugh Jul-1997 for Tubmud
 *
 * this will be inherited by anything that can defend.
 */

#include <event.h>
#include <combat.h>

private static mixed *defenses;

mixed *get_defenses() {
  return (defenses || ({})) - ({0});
}

void add_defense(mixed def) {
  defenses = get_defenses()+({def});
}

void remove_defense(mixed def) {
  defenses = get_defenses()-({def});
}

// to be overloaded
object get_defense(mixed def) {
  return def;
}

status should_defend(mapping against) {
  object body, target;

  // defend only against attacks with a target
  if (against[E_TYPE,1] != "attack" || 
      !(target = against[E_TARGET]))
    return 0;

  // against attacks against ourselves
  if (target == this_object())
    return 1;
  // if we have a body
  if (body = this_object()->query_body()) {
    // against our body
    if (target == body)
      return 1;
    // or its parts
    if (body->query_bodypart(target,1))
      return 1;
  }
  // against attack against our equipment, as well
  if (present(target,this_object()))
    return 1;
}

status query_defending(mapping against) {
  int i;
  mixed h;

  h = get_defenses();
  for (i = sizeof(h); i--; )
    if (get_defense(h[i])->query_defending(against))
      return 1;
  return 0;  // Coogan, 24-Mar-2011
}

void try_begin_defense(mapping against) {
  mixed h;
  object c, best_defense;
  int i, d, best_defense_chance;

  if (!(c = COMBAT)->query_coordinating(this_object()))
    c->start_coordinating(this_object());
  h = filter(get_defenses(),#'get_defense);
  h = filter_objects(h,"can_defend",against);

  for (i = sizeof(h); i--; )
    if ((d = h[i]->should_defend(against)) > best_defense_chance) {
      best_defense_chance = d;
      best_defense = h[i];
    }
  if (best_defense)
    best_defense->begin_defense(against);
}

void try_defense(mapping against) {
  filter_objects(filter_objects(filter(get_defenses(),#'objectp),
                                "query_defending",against),"defend",against);
}

// modify attacks by defending against them
private void modify_attack_action(mapping e, string t, int p) {
  switch (t) {
    case "action":
      with_player(this_object(),#'try_defense,e);
      break;
  }
}

// react on the begin of attacks starting of defense
private void react_attack_action(mapping e, string t, int p) {
  switch (t) {
    case "begin_action":
      if (should_defend(e))
        with_player(this_object(),#'try_begin_defense,e);
      break;
  }
}

public void init_defenses() {
  listen_event("action",500,#'modify_attack_action);
  listen_event("begin_action",-100,#'react_attack_action);
}
