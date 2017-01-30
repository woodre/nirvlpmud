/***************************************************************************
      compound_bodypart.c -- bodypart consisting of other bodyparts
		    written by Ugh for Tubmud 1997
***************************************************************************/

#include <bodypart.h>

inherit BASIC_BODYPART_COMPOUND;
inherit BASIC_BODYPART;

/**************************************************************************/

void init_component() {
  BASIC_BODYPART::init_component();
  BASIC_BODYPART_COMPOUND::init();
}

varargs void add_compound_action(string func, string verb, int flag) {
  add_component_action(func,verb,flag);
}

varargs void add_compound_action_rule(string rule, string action, mixed func) {
  add_component_action_rule(rule,action,func);
}

mixed receive_call_component(string name, string func, varargs args) {
  mixed h;

  if (h = get_component(&name))
    return apply(#'call_other,h,"receive_call_component",name,func,args);
  else
    return apply(#'call_other,this_object(),func,args);
}

mixed call_component(string name, string func, varargs mixed args) {
  mixed h;

  if (h = get_component(&name))
    return
      apply(#'call_other,h,"receive_call_component",name,func,args);
  else
    return
      apply(#'call_other,get_compound(),"call_component",name,func,args);
}

status id(string str) {
  return BASIC_BODYPART::id(str) || BASIC_BODYPART_COMPOUND::id(str);
}

/*************************** Armours **************************************/

varargs status can_wear(object armour) {
  return
    BASIC_BODYPART::can_wear(armour) &&
    BASIC_BODYPART_COMPOUND::can_wear(armour);
}

varargs void wear(object armour) {
  BASIC_BODYPART::wear(armour);
  BASIC_BODYPART_COMPOUND::wear(armour);
}

status can_unwear(object armour) {
  return
    BASIC_BODYPART::can_unwear(armour) &&
    BASIC_BODYPART_COMPOUND::can_unwear(armour);
}

void unwear(object armour) {
  BASIC_BODYPART::unwear(armour);
  BASIC_BODYPART_COMPOUND::unwear(armour);
}

/***************************** Resources ************************************/

varargs void wait_for_bodypart(object ob, string part) {
  mixed h;

  if (h = get_bodypart(&part))
    return h->wait_for_bodypart(ob,part);
  BASIC_BODYPART::wait_for_bodypart(ob);
}

varargs void stop_waiting_for_bodypart(object ob, string part) {
  mixed h;

  if (h = get_bodypart(&part))
    return h->stop_waiting(ob,part);
  BASIC_BODYPART::stop_waiting_for_bodypart(ob);
}

varargs status deactivate_bodypart(mapping marked) {
  status result;

  if (!marked)
    marked = ([]);
  else if (member(marked,this_object()))
    return 0;
  result = BASIC_BODYPART::deactivate_bodypart(marked);
  map_objects(get_bodyparts(),"deactivate_bodypart",marked);
  return result;
}

void deactivate_component_bodypart(object part, mapping marked) {
  int i, j;
  mixed h, c;

  h = get_depending_bodyparts();
  c = part->get_bodypart_connectors();
  for (i = sizeof(h); i--; )
    for (j = sizeof(c); j--; )
      if (call_component(h[i],"query_connected_to_bodypart",this_object(),c[j]))
	call_component(h[i],"deactivate_bodypart",marked);
  if (!sizeof(filter_objects(get_bodyparts(),"query_active_bodypart")))
    BASIC_BODYPART::deactivate_bodypart(marked);
}

varargs status activate_bodypart(mapping marked) {
  status result;

  if (!marked)
    marked = ([]);
  else if (member(marked,this_object()))
    return 0;
  result = BASIC_BODYPART::activate_bodypart(marked);
  map_objects(get_bodyparts(),"activate_bodypart",marked);
  return result;
}

void activate_component_bodypart(object part, mapping marked) {
  int i, j;
  mixed h, c;

  h = get_depending_bodyparts();
  c = part->get_bodypart_connectors();
  for (i = sizeof(h); i--; )
    for (j = sizeof(c); j--; )
      if (call_component(h[i],"query_connected_to_bodypart",this_object(),c[j]))
	call_component(h[i],"activate_bodypart",marked);
  if (sizeof(filter_objects(get_bodyparts(),"query_active_bodypart")))
    BASIC_BODYPART::activate_bodypart(marked);
}

varargs status can_use_bodypart(mixed action, string part) {
  int i;
  mixed h;
  object p;

  if (!BASIC_BODYPART::can_use_bodypart(action))
    return 0;
  if (part && p = get_bodypart(&part))
    return p->can_use_bodypart(action,part);
  h = get_bodyparts();
  for (i = sizeof(h); i--; )
    if (!h[i]->can_use_bodypart(action))
      return 0;
  return 1;
}

varargs status can_share_bodypart(mixed action, string part) {
  int i;
  mixed h;
  object p;

  if (!BASIC_BODYPART::can_share_bodypart(action))
    return 0;
  if (part && p = get_bodypart(&part))
    return p->can_share_bodypart(action,part);
  h = get_bodyparts();
  for (i = sizeof(h); i--; )
    if (!h[i]->can_share_bodypart(action))
      return 0;
  return 1;
}

varargs status can_free_bodypart(mixed action, string part) {
  int i;
  mixed h;
  object p;

  if (!BASIC_BODYPART::can_free_bodypart(action))
    return 0;
  if (part && p = get_bodypart(&part))
    return p->can_free_bodypart(action, part);
  h = get_bodyparts();
  for (i = sizeof(h); i--; )
    if (!h[i]->can_free_bodypart(action))
      return 0;
  return 1;
}

varargs void use_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->use_bodypart(action,part);
  else
    return BASIC_BODYPART::use_bodypart(action);
}

varargs void share_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->share_bodypart(action,part);
  else
    return BASIC_BODYPART::share_bodypart(action);
}

varargs void free_bodypart(mixed action, string part) {
  object p;

  if (part && p = get_bodypart(&part))
    return p->free_bodypart(action,part);
  else
    return BASIC_BODYPART::free_bodypart(action);
}

/******************************** Side ***************************************/

void add_position(string pos, int explicit) {
  BASIC_BODYPART::add_position(pos,explicit);
  if (pos == "left" || pos == "right")
    filter_objects(get_bodyparts(),"add_position",pos,explicit);
}

/************************** User/Owner ************************************/

void set_user(object u) {
  BASIC_BODYPART_COMPOUND::set_user(u);
  BASIC_BODYPART::set_user(u);
}

mixed get_component_state() {
  return
    ([ "compound_state" : get_compound_state(),
       "component_state" : BASIC_BODYPART::get_component_state() ]);
}

void set_component_state(mapping state) {
  set_compound_state(state["compound_state"]);
  BASIC_BODYPART::set_component_state(state["component_state"]);
}

void notify_destruct() {
  BASIC_BODYPART::notify_destruct();
  BASIC_BODYPART_COMPOUND::notify_destruct();
}
