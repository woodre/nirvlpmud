/*****************************************************************************
      compound.c -- basic class for use of function get_component()
                written by Ugh Nov-1996 for Tubmud
*****************************************************************************/

/*
 * This class tries to implement an is-component-of relation between
 * two objects.
 * An object can be component of several compound objects.
 * Since that is so, there can be no definite mapping from component
 * to compound. Also, an object cannot be a component of itself.
 *
 * The following is true:
 * ob is-component-of compound <== compound->query_component(ob)
 *
 * But, almost all things that have to do with components are handled
 * internally (from an information-hiding point of view, if you will), an
 * have thus to be implemented 'superficially' by the compound itself
 * which then relays the specific requests to its component(s).
 *
 * Thus, the most important change in the mudlib, that has to be done,
 * is the calling of:
 * add_inventory(ob,id [,preposition] ) 
 *      (if somebody wants to 'put' something
 *      into an object) and
 * ob->get_inventory(id [,preposition] )||all_inventory(ob)
 *      instead of just all_inventory(ob),
 *      if objects 'inside' one of our components
 *      should be manipulatable (e.g. objects in one of
 *      five drawers that are all part of a desk).
 */

#include <regexps.h>
#include <inventory.h>

private string *component_names;
private mapping components;

varargs object get_component(string name, status deep);
object find_component(string name);

mixed call_component(string name, string func, varargs mixed args) {
  mixed h;

  if (h = get_component(&name))
    return apply(#'call_other,h,"receive_call_component",name,func,args);
}

// this function works similar to all_inventory()
string *all_components() {
  // first subtract destructed objects
  return
    component_names || ({});
}

// this function works similar to deep_inventory()
object *deep_components() {
  mixed h;

  h = all_components();
  return
    h+flatten_array(map(h,#'call_component,"deep_components")-({0}));
}

varargs status query_component(mixed c, status deep) {
  mixed h;

  if (stringp(c)) {
    if (h = find_component(c))
      return
        (deep && get_component(c)->query_component(c,deep)) || 1;
  } else if (objectp(c)) {
    if (objectp(h = find_component(c->get_component_name())))
      return
        h == c || (deep && h->query_component(c,deep));
  }
}

void remove_component(mixed component) {
  mixed h;

  if (!components)
    return;
  if (stringp(component)) {
    if (h = find_component(&component)) {
      if (stringp(h))	{ // found only a saved component
        m_delete(components,h);
        component_names -= ({ h });
      } else {
        m_delete(components,component);
        component_names -= ({component});
        h->remove_compound();
      }
    }
  } else if (objectp(component)) {
    if (h = component->get_component_name()) {
      m_delete(components,h);
      component_names -= ({h});
      component->remove_compound();
    }
  }
}

void add_component(object component) {
  string name;

  if (component == this_object() ||
      component->has_deep_component(this_object()))
    raise_error("Compound can't be component of itself.\n");
  if (!components) {
    components = ([ ]);
    component_names = ({});
  }
  // check for cycles first
  // ... still to be implemented ...
  name = component->get_component_name();
  // since name must be unique ...
  remove_component(name);
  components += ([ name : component ]);
  component_names += ({ name });
  component->set_compound(this_object());
}

static mapping component_state(string name) {
  mixed h, component;

  if (mappingp(component = components[name]))
    return component;
  // now get the state of the component
  h = ([ "state" : component->get_component_state() ]);
  // save necessary additional data for restoration
  h["cloned"] = clonep(component);
  h["load_name"] = load_name(component);
  return h;
}

mapping get_compound_state() {
  return map_indices(mkmapping(all_components()),#'component_state);
}

void set_compound_state(mapping state) {
  components = copy(state);
  component_names = m_indices(state);
}

static varargs void save_component(string name, status force) {
  mapping h;
  object component;

  if (mappingp(components[name]))	// already saved
    return;
  if (!(force || components[name]->query_saveable()))
    return;
  component = components[name];
  // first let the component save all its components (if it is a compound),
	// and other necessary data so that none are lost
  component->compound_save_component(force);
  h = component_state(name);
  h["id"] =
    (component->query_id() || ({})) +
    (component->deep_components() || ({}));
  components[name] = h;
  component->remove_compound();
  destruct(component);
}

public void save_compound(status force) {
  int i;

  if (!components)
    return;
  for (i = sizeof(component_names); i--; )
    save_component(component_names[i], force);
}

static object restore_component(string name) {
  mixed h;
  object component;

  h = components[name];
  if (!mappingp(h))
    return h;
  if (h["cloned"])
    component = clone_object(h["load_name"]);
  else
    component = load_object(h["load_name"]);
  component->set_component_state(h["state"]);
	// component->compound_restore_component();
  return components[name] = component;
}

static status component_id(string name, string str) {
  mixed h;

  if (name == str)
    return 1;
  if (mappingp(h = components[name]))
    return member(h["id"],str) >= 0;
  if (h)
    return
      h->query_component_id(str) ||
      h->id(str) ||
      member(h->deep_components() || ({}),str) >= 0;
}

static mixed present_component(string id, string *names) {
  int i, number;
  string identifier;
  mixed h;

  for (i = sizeof(names); i; i--)
    if (component_id(names[<i],id))
      return mappingp(h = components[names[<i]]) ? names[<i] : h;
  if (sizeof(h = explode(id," ")) >= 2 &&
      IS_REGEXP(h[<1],REGEXP_UNSIGNED_INT) &&
      (number = to_int(h[<1])) > 0 && sizeof(names) >= number) {
    identifier = implode(h[0..<2]," ");
    for (i = sizeof(names); i; i--) {
      if (component_id(names[<i],identifier))
        number--;
      if (!number) {
        id = identifier;
        return mappingp(h = components[names[<i]]) ? names[<i] : h;
      }
    }
  }
  return 0;  // Coogan, 26-Mar-2011
}

static mixed *present_components(string identifier, string *names) {
  return
    filter(names,#'component_id,identifier);
}

mixed find_component(string id) {
  mixed h;

  if (!(components && id))
    return 0;
  if (member(components,id)) {
    h = components[id];
    if (objectp(h))
      return h;
    else
      return id;
  }
  return
    present_component(&id,component_names);
}

/*
 * The function get_component() is the heart of this class.
 * If the given argument is a component of this_object(), it should
 * return something that can serve as first argument to call_other()
 * (i.e. an object or something that is understood by find_object() or
 * load_object()).
 * The argument will be given as id-string
 * (a string for which the wanted component's id()-function returns true)
 * with the possibility of an appended number
 * (in case there are several objects with the same id) like in the
 * function present().
 *
 * The id-string may be passed call-by-ref and will be changed, if 
 * any numbers at the end have been cut off.
 */
varargs object get_component(string id, status deep) {
  mixed h;

  if (id && h = find_component(&id)) {
    if (stringp(h))		// found a saved component
      h = restore_component(h);
    return
      (deep && h->get_component(&id,deep)) || h;
  }
}

/*
 * Per default, every component is accessible for everybody that has
 * access to the compound object.
 * Overload this function, if you want to make certain components
 * not accessible in certain situations (e.g. components that are not
 * visible, because they are inside an object that is closed).
 */
status query_accessible(mixed component, object to) {
  return 1;
}

varargs mixed *accessible_components(object player,status deep) {
  if (deep)
    return
      filter(deep_components(),#'query_accessible,player);
  else
    return
      filter(all_components(),#'query_accessible,player);
}

varargs mixed get_components(mixed identifier, status deep, status accessible) {
  int i;
  mixed *c, h;

  if (identifier)
    c = present_components(identifier,
                           accessible ?
                           accessible_components(this_player()) :
                           all_components());
  else
    c = accessible ?
        accessible_components(this_player()) :
	all_components();
  c = map(c,"get_component");
  if (deep) {
    for (i = sizeof(c); i--; )
      if (sizeof(h = c[i]->get_components(identifier,1)))
        c[i] = h;
    c = flatten_array(c);
  }
  return c;
}

/*****************************************************************************
    here comes the part that deals with actions added by components
                            of this compound
*****************************************************************************/

// for every player, store a stack of actions, added by components
private static mapping added_component_actions;
private static mapping added_component_action_rules;

void init() {
  // first remove all added component actions for this_player()
  // since the player comes into new contact with us, obviously
  if (added_component_actions)
    m_delete(added_component_actions,this_player());
  if (added_component_action_rules)
    m_delete(added_component_action_rules,this_player());
  // all objects that are accessible to this_player() 
  // should have the possibility to add their actions
  filter(all_components(),#'call_component,"init_component");
}

// this function is used by parse_component_action() to
// determine, which of the added actions are valid for the given command
private status added_component_actions_filter(mixed *action, string verb) {
  // action has the form ({verb, flags, object, function})
  if (action[1]) // flags set
    return
      strstr(verb,action[0]) == 0;
  else
    return
      verb == action[0];
}

varargs void add_compound_action(varargs mixed args) {
  apply(#'add_action,args);
}

// this function is called by components,
// therefore, components have to inherit basic/component which
// modifies their add_action() that it works this way
// don't call this function yourself to add a component-action
// use add_componen_action() in the component for that
public void component_add_action(string func,string verb,int flags) {
  status new_verb;

  if (!added_component_actions)
    added_component_actions = ([]);
  if (!member(added_component_actions,this_player())) {
    added_component_actions += 
      ([ this_player() :
          ({ ({verb, flags,
               previous_object()->get_component_name(), func}) }) ]);
    new_verb = 1;
  } else {
    new_verb =
      !sizeof(filter(added_component_actions[this_player()],
                           #'added_component_actions_filter,
                           verb));
    // they are evaluated in decreasing order later
    added_component_actions[this_player()] += 
      ({ ({verb, flags,
           previous_object()->get_component_name(), func}) });
  }
  if (new_verb) 
    add_compound_action("parse_component_action",verb,flags);
}

status parse_component_action(string str) {
  int i;
  mixed *list;
  object ob;

  list = filter(added_component_actions[this_player()],
                      #'added_component_actions_filter,
                      query_verb());
  // list has now the form ({ ({verb, flag, object, function}), ... })
  // evaluate from rear to front
  for (i = sizeof(list); i--; )
    // is object still existent and handled the action?
    if ((ob = get_component(list[i][2])) &&
        query_accessible(ob,this_player()) &&
        call_other(ob,list[i][3],str))
      return 1;
  return 0;  // Coogan, 26-Mar-2011
}

varargs int remove_component_action(string verb, object ob) {
  return 0;  // Coogan, 26-Mar-2011
}

// this function is called if an action-rule of a component is matched
// the rule which matched is passed as argument 'action'
// static
mixed do_component_action(string action, mapping args) {
  int i;
  mixed h, result;
  object ob;

  if (!(added_component_action_rules &&
        (h = added_component_action_rules[this_player()]) &&
        sizeof(h = h[action])))
    return 0;
  for (i = sizeof(h); i--; )
    // h[i] now has the form: ({ component, function_or_closure, action_id })
    if ((ob = get_component(h[i][0])) &&
        query_accessible(ob,this_player()) &&
        (result = call_other(ob,h[i][1]||"do_action",h[i][2],args)))
      return result;
  return 0;  // Coogan, 26-Mar-2011
}

varargs void add_compound_action_rule(string rule, string action, mixed func) {
  add_action_rule(rule,action,func);
}

// This function is called by add_component_action_rule() in the component
// see also the comment to component_add_action()
public void component_add_action_rule(string rule, string action, mixed func) {
  if (!added_component_action_rules)
    added_component_action_rules = ([]);
  if (!member(added_component_action_rules,this_player()))
    added_component_action_rules[this_player()] = 
      ([ rule : ({ ({ previous_object()->get_component_name(),
                      func, action}) }) ]);
  else if (!member(added_component_action_rules[this_player()],rule))
    added_component_action_rules[this_player()] += 
      ([ rule : ({ ({ previous_object()->get_component_name(),
                      func, action }) }) ]);
  else {
    added_component_action_rules[this_player()][rule] += 
      ({ ({ previous_object()->get_component_name(), func, action }) });
    // in this case, don't add the new rule again
    return;
  }
  add_compound_action_rule(rule, rule, "do_component_action");
}

mixed do_take_action(string item) {
  mixed h;
  if (item && h = get_component(&item))
    return h->do_take_action(item);
}

mixed apply_action(varargs mixed vargs) {
  mixed h, result;
  int i;

  h = accessible_components(this_player());
  for (i = sizeof(h); i; i--)
    if (result = apply(#'call_component,h[<i],"apply_action",vargs))
      return result;
  return 0;  // Coogan, 26-Mar-2011
}

/****************************************************************************
      Some local functions that have to be exported from the components
****************************************************************************/

private status deep_present(object ob, object where) {
  while (ob = environment(ob))
    if (where == ob)
      return 1;
  return 0;  // Coogan, 26-Mar-2011
}

/*
 * Normally, id() should be true for every component that is accessible
 * to this_player().
 */
status id(string str) {
  mixed h;

#if 0 // Ugh - the parser handles components
  if (str && (h = find_component(str))) {
    if (!objectp(h) || !environment(h) || deep_present(h,this_object()))
      return 1;
  }
#endif
  return 0;  // Coogan, 26-Mar-2011
}

status query_component_id(string str) {
  return str && find_component(str) && 1;
}

varargs string query_name(string str) {
  mixed h;

  if (str && h = get_component(&str))
    return h->query_name(str);
}

// does anybody want to put something into or get something from one
// of our components, let the component handle that.
varargs status can_put_and_get(string str, object ob) {
  mixed h;
  if (str && h = get_component(&str))
    return h->can_put_and_get(str,ob);
}

// is anybody looking at the inventory of one of our components,
// let the component decide, wether it shows it or not
status hide_inventory(string str) {
  mixed h;
  if (str && h = get_component(&str))
    return h->hide_inventory(str);
}

// If an object wants to manipulate (or show) the objects 'in' a 
// compound object, it should get the inventory with this function
varargs object * get_inventory(string which, string preposition) {
  mixed h;
  if (which && h = get_component(&which))
    return h->get_inventory(which,preposition) || all_inventory(h);
}

// This function is called if somebody tries to 'put' something into
// us and wants to know, if we want to handle this 'putting' ourselves.
// If they want to 'put' the object into one of our components, let
// the component handle that.
varargs status add_inventory(object ob, string which, string preposition) {
  mixed h;
  if (which && h = get_component(&which))
    return h->add_inventory(ob,which,preposition);
}

// this is for the case that our long() is overloaded 
string query_component_long(string str) {
  mixed h;
  if (h = get_component(&str))
    return h->long(str);
}

// Is somebody asking for the long-description of one of our components?
// ask the component for its long-description, then
// This is very similar to fakeitems
string long(string str) {
  mixed h;
  if (str && h = query_component_long(str))
    return h;
}

// Every component could have an own gender, so if somebody asks for
// the gender of one of our components, let the component decide, what
// gender it possesses.

varargs int query_gender(string str) {
  mixed h;
  if (str && h = get_component(&str))
    return h->query_gender(str);
}

// normally, an object should not be gettable, if someone tries to get
// one of its components
status get(string str) {
  if (str && get_component(&str))
    return 0;
  return 1;
}

// varargs, Coogan, 27-Sep-2010
varargs int query_value(string str) {
  mixed h;

  if (str && (h = get_component(&str)))
    return h->query_value(str);
  return fold_left(#'+,map_objects(get_components(),"query_value"));
}

// varargs, Coogan, 27-Sep-2010
varargs int query_encumbrance(string str) {
  mixed h;

  if (str && (h = get_component(&str)))
    return h->query_encumbrance(str);
  return fold_left(#'+,map_objects(get_components(),"query_encumbrance"));
}

mixed query_property(string prop, string str) {
  mixed h;

  if (str && h = get_component(&str))
    return h->query_property(prop,str);
}
