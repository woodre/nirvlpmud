/******************************************************************************
          basic/wearable.c -- written by Ugh for Tubmud Jul-1997
        an interface for objects that can be worn by other objects
            this interface depends very much on basic/wear.c
******************************************************************************/
#include <message.h>
#include <event.h>

string query_name();

// We are recording who is wearing us on which part of theirs 
// The 'where' is only given for the case that we want to delegate this
// functionality (like a compound that delegates it to one of its components
// that is _really_ worn instead of the whole compound)
// (like a robe to its sleeve for the wearing on the arm)

private static mapping worn;           // (part_id -> part)
private static object wearer;          // who is wearing us

// The arguments frequently used in this file mean the following:
// 'who' -- who is wearing us
// 'part' -- on what part 
// 'location' -- which part of ours

object get_wearer() {
  return wearer;
}

void set_wearer(object who) {
  wearer = who;
}

private string* get_worn_on() {
  return worn ? m_indices(worn) : ({});
}

private object get_wearing_part(string part) {
  if (worn && member(worn,part))
    return 
      worn[part] ||
      (worn[part] = get_wearer()->get_component(part,1));
}

// if the wearer isn't wearing this, return 0
object* get_wearing_parts() {
  return
    map(get_worn_on(),#'get_wearing_part);
}

varargs status query_worn(object who, mixed part) {
  if (!who)
    return worn && sizeof(worn) > 0;
  if (!part)
    return get_wearer() == who;
  if (objectp(part))
    part = part->query_real_name();
  return worn && query_worn(who) && member(worn,part);
}

// return the location of the clothing that
// would (or does) cover 'who's part' 
string get_worn_location(object who, object part) {
  return query_name();
}

status query_wearable(object who, object part) {
  return !query_worn();
}

// this function should return true, if the clothing is rigid on
// the given location
int query_rigid(string location) {
  return 0;  // Coogan, 27-Mar-2011
}

int query_overlaying(string location, object cover, string cover_location) {
  return 1;
}

// this function should return true, if the given cover would prevent
// overlaying of this new cover
int prevent_overlay(string location, object cover, string cover_location) {
  // prevent overlay of two rigid covers
  if (query_overlaying(location,cover,cover_location) &&
      query_rigid(location) && cover->query_rigid(cover_location))
    return 1;
}

int prevent_unwear(object who, mixed part) {
  return 0;  // Coogan, 27-Mar-2011
}

void notify_wear(object who, mixed part) {
  set_wearer(who);
  if (!worn)
    worn = ([]);
  if (objectp(part))
    worn += ([ part->query_real_name() : part ]);
  else
    worn += ([ part : 0 ]);
}

status drop(status silently) {
  if (query_worn()) {
    if (!silently)
      write(message2string(({M_CAPITALIZE,M_ME_THE,M_ME_VERB,"have",
                             " to be taken off, first.\n"})));
    return 1;
  }
}

status prevent_drop() {
  return query_worn() || drop(1);
}

void drop_item();

// we can only be removed, if we're worn
void notify_unwear(object who, mixed part) {
  if (objectp(part))
    part = part->query_real_name();
  m_delete(worn,part);
  if (!sizeof(worn))
    set_wearer(0);
  if (!prevent_drop())
    drop_item();
}

string query_wear_description(status in_output) {
  if (query_worn(environment()))
    return "worn";
  else if (!in_output)
    return
      "not worn";
}

status prevent_prepare_action_event(mapping e) {
  if (e[E_ACTION] == "undress" && 
      e[E_TARGET] == this_object() && e[E_AGENT] != e[E_RECIPIENT])
    if (!e[E_RECIPIENT]->is_offered(e[E_TARGET],e[E_AGENT],e[E_TARGET,1]))
      return e[E_TOOL]->fail_action("Failed.\n"), 1;
}
