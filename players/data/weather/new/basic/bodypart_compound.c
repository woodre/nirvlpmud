/***************************************************************************
          bodypart_compound.c -- compound consisting of bodyparts
                    written by Ugh for Tubmud 1997
***************************************************************************/

#pragma strong_types

#include <bodypart.h>

inherit "basic/compound";
inherit "basic/hittable";

/************************ Bodyparts/Connections ***************************/

status query_connected_bodyparts(object part1, object part2) {
  return part1->query_connected_to_bodypart(part2);
}

// made mixed, Coogan, 27-Sep-2010
void disconnect_bodyparts(mixed part1, mixed part2) {
  if (stringp(part1))
    call_component(part1,"disconnect_from_bodypart",part2);
  else
    part1->disconnect_from_bodypart(part2);
  if (stringp(part2))
    call_component(part2,"disconnect_from_bodypart",part1);
  else
    part2->disconnect_from_bodypart(part1);
}

void connect_bodyparts(object part1, object part2, string at1, string at2) {
  // part1 is the depending, part2 the part upon which part1 is depending
  // at is the location on the bodyparts where they are connected:
  // e.g. connect_bodyparts(left_arm,torso,"left shoulder");

  // first, disconnect them (in case they were already connected),
  // This means, that two bodyparts can only be connected in one place

  part1->disconnect_from_bodypart(part2);
  part2->disconnect_from_bodypart(part1);

  if (!at2)
    at2 = at1;

  // Now, connect them at the given places.

  // connect the depending bodypart to the other one
  part2->connect_with_bodypart(part1,at2,at1);
}

varargs object * get_bodyparts(string location,status deep) {
  return
    filter_objects(get_components(location,deep),"query_property",P_BODYPART);
}

varargs status query_bodypart(object part, status deep) {
  if (query_component(part,deep) && part->query_property(P_BODYPART))
    return 1;
}

string query_race();

varargs void add_bodypart(object part) {
  if (environment())
    move_object(part,environment());
  else
    move_object(part,this_object());
  add_component(part);
  part->set_race(query_race());
}

void remove_bodypart(object part) {
  if (environment(part) == this_object())
    raise_error("Can't remove bodypart.\n");
  if (query_component(part)) {
    if (query_bodypart(part))
      map(part->get_connected_bodyparts(),#'disconnect_bodyparts,part);
    return remove_component(part);
  }
  else
    filter_objects(get_bodyparts(),"remove_bodypart",part);
}

varargs object get_bodypart(string part, status deep) {
  object h;

  h = get_component(&part,deep);
  if (h)
    return query_bodypart(h,deep) && h;
}

status query_connector_id(string str) {
  mixed h;

  if (str && h = get_bodypart(&str))
    return h->query_connector_id(str);
}

void notify_destruct() {
  int i;
  mixed h;

  h = get_bodyparts();
  for (i = sizeof(h); i--; )
    if (h[i])
      destruct(h[i]);
}

/***************************** Resources ************************************/

varargs void wait_for_bodypart(object ob, string part) {
  mixed h;
  
  if (part && h = get_bodypart(&part))
    return h->wait_for_bodypart(ob,part);
}

varargs void stop_waiting(object ob, string part) {
  mixed h;

  if (part && h = get_bodypart(&part))
    return h->stop_waiting(ob,part);
}

varargs status can_use_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->can_use_bodypart(action,part);
}

varargs status can_share_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->can_share_bodypart(action,part);
}

varargs status can_free_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->can_free_bodypart(action,part);
}

varargs void use_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->use_bodypart(action,part);
}

varargs void share_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->share_bodypart(action, part);
}

varargs void free_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->free_bodypart(action,part);
}

/************************ Hit Locations *************************************/

void set_user(object u) {
  filter_objects(get_bodyparts(),"set_user",u);
}

status try_defense(mapping attack) {
  return sizeof(filter_objects(get_bodyparts(),"try_defense",attack)) > 0;
}

/************************** Weapons ****************************************/

varargs status query_wielding(object thing) {
  int i;
  mixed h;

  for (i = sizeof(h = get_components()); i--; )
    if (h[i]->query_wielding(thing))
      return 1;
}

object get_holding_part(string str) {
  mixed h;

  if (h = get_component(&str))
    return h->get_holding_part(str) || h;
  return this_object();
}

/************************** Clothing ***************************************/

status can_wear(object clothing) {
  int i;
  mixed h;

  for (i = sizeof(h = get_bodyparts()); i--; )
    if (!h[i]->can_wear(clothing))
      return 0;
  return 1;
}

void wear(object clothing) {
  map_objects(get_bodyparts(),"wear",clothing);
}

status can_unwear(object clothing) {
  int i;
  mixed h;

  for (i = sizeof(h = get_bodyparts()); i--; )
    if (!h[i]->can_unwear(clothing))
      return 0;
  return 1;
}

void unwear(object clothing) {
  map_objects(get_bodyparts(),"unwear",clothing);
}

object *get_covered_bodyparts(object clothing) {
  int i;
  mixed h;
  object *result;

  result = ({});
  for (i = sizeof(h = get_bodyparts()); i--; )
    if (h[i]->query_wearing(clothing))
      result += ({ h[i] });
    else 
      result += h[i]->get_covered_bodyparts(clothing) || ({});
  if (sizeof(result))
    return result;
}

object *get_inventory(string which, string preposition) {
  int i;
  mixed h, inv;
  object *result;
  mapping found;

  if (h = compound::get_inventory(which,preposition))
    return h;
  h = all_inventory();
  result = ({});
  found = m_allocate(sizeof(h),0);
  for (i = sizeof(h); i; i--) {
    if (!member(found,h[<i])) {
      found += ([ h[<i] ]);
      result += ({ h[<i] });
      inv = h[<i]->get_inventory(0,preposition) || all_inventory(h[<i]);
      inv -= filter(inv,sort_args(#'member),found);
      found += mkmapping(inv);
      result += inv;
    }
  }
  return result;
}
