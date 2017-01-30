/*
 * defense.c -- written by Ugh Jul-1997 for Tubmud
 *
 * this will be inherited by anything that can be defended with.
 */

#include <event.h>

// The next few functions _have_ to be implemented by a class
// inheriting us or a class that is inherited by the class inheriting us

// true, if it is possible to defend against that attack
status can_defend(mapping against);

// true if it is sensible to defend against that attack
status should_defend(mapping against);

// true if this object is defending against that attack
status query_defending(mapping against);

// schedule the action resulting in the defense-reaction
void begin_defense(mapping against);

// modify the attack-event and finish the defense
void defend(mapping against);

object get_user();

void set_user(object u) {
  mixed h;

  if (h = get_user())
    h->remove_defense(this_object());
  if (u)
    u->add_defense(this_object());
}

// next three lfuns needed by basic/new_weapon, Coogan, 18-Oct-2000
public status handle_event(mapping e, string type, int p) {
  return 0;  // Coogan, 26-Mar-2011
}

public status modify_event(mapping e, string type, int p) {
  return 0;  // Coogan, 26-Mar-2011
}

public status react_event(mapping e, string type, int p) {
  return 0;  // Coogan, 26-Mar-2011
}

