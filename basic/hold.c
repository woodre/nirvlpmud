/*
 * /basic/hold.c
 *
 * An interface for objects that can hold other objects like hands, pincers,
 * etc... This interface depends on basic/holdable.c
 */

#include <prop/item.h>

object get_user();

// We only record what we are holding (and what we're wielding thereof)
// We depend on the fact that the wielded item records, where we wield it

private static mapping holding;     // (held)
                                    // object contained in mapping means: held
                                    // value for object true means: wielded

private static int hold_size;       // how much can we get in our hold

object *get_held();
object *get_wielded();

status query_holding(object thing);
status query_wielding(object thing);

status can_hold(object thing, string id);
status can_let_go(object thing);
status can_wield(object thing);

void hold(object thing, string id);
void let_go(object thing);

void set_hold_size(int s) {
  hold_size = s;
}

private void set_holding(mapping h) {
  holding = h;
}

private mapping get_holding() {
  return m_delete(holding,0);
}

status query_holding(object thing) {
  return
    thing && member(holding,thing);
}

status query_wielding(object thing) {
  return
    query_holding(thing) &&
    thing->query_wielded_by(get_user(),this_object());
}

object *get_held() {
  return m_indices(get_holding());
}

object *get_wielded() {
  return filter(get_held(),#'query_wielding);
}

object get_holding_part(string name) {
  return this_object();
}

string get_hold_location(object thing) {
  return
    query_holding(thing) &&
    (thing->get_held_location(get_user(),this_object()) ||
     thing->query_name());
}

// return the size we _can_ hold
int get_hold_size() {
  return hold_size;
}

// return the size we _do_ hold
int get_held_size() {
  int i, s;
  mixed h;

  for (i = sizeof(h = get_held()); i-->0; )
    s += h[i]->get_hilt_size(get_hold_location(h[i]));
  return s;
}

status can_hold(object thing, string where) {
  int s;
  mixed w;

  if (!thing)
    return 0;
  // already holding
  if (query_holding(thing))
    return 0;
  if (sizeof(get_wielded()))
    return 0;
  if (thing->query_property(P_NOT_HOLDABLE,where) ||
      thing->prevent_hold(get_user(),where,this_object()))
    return 0;
  if (thing->query_unreachable(this_object()))
    return 0;
  // compute the size of the different things wielded
  // Thus, we could wield several 'small' things simultaneously
  // this is a very crude test and should be made better somewhen
  if (get_hold_size() < get_held_size() + thing->get_hilt_size(where))
    return 0;
  return 1;
}

void hold(object thing, string where) {
  thing->notify_hold(get_user(),where,this_object());
  holding += ([thing]);
}

status can_let_go(object thing) {
  if (!thing)
    return 0;
  if (!query_holding(thing))
    return 0;
  if (query_wielding(thing))
    return 0;
  return
    !thing->prevent_let_go(get_user(),
                           get_hold_location(thing),
                           this_object());
}

void let_go(object thing) {
  thing->notify_let_go(get_user(),get_hold_location(thing),this_object());
  m_delete(holding,thing);
}

status can_wield(object thing) {
  if (!query_wielding(thing))
    return
      (query_holding(thing) &&
       sizeof(get_held()) == 1) ||
      !sizeof(get_held());
}

void notify_destruct() {
//  map(get_held(),#'let_go);
}

void create() {
  holding = ([]);
}

