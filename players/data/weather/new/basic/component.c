/****************************************************************************
        component.c -- written by Ugh for Tubmud Nov-1996
    a possibility for objects that are not 'present' to this_player(),
    but are components of objects which are, to add actions for
              this_player() inside themselves, as well
****************************************************************************/

// this function is used by the functions below. It checks, wether
// this_player() is 'present' to this_object()
private status this_player_is_present() {
  return
    this_player() && this_object() &&
    (this_player() == this_object() ||
     this_player() == environment() ||
     environment(this_player()) &&
     (environment(this_player()) == this_object() ||
      environment(this_player()) == environment()));
}

// this function returns true, if the string str is an adequate description
// of this_object(), e.g. is an id of it, or is a component-description
// of this component from the calling compound (if this_player() is not
// 'present', or, (otherwise) if str is a description for present()
// Thus, it is very unimportant for this_object(), wether it is used
// as component, and also, where it is residing

string get_component_name();

status id(string str) {
  // return str == get_component_name();
  return 0;  // Coogan, 26-Mar-2011
}

static object get_calling_compound() {
  int i;
  mixed h;

  h = previous_object();
  while (h && h == this_object())
    h = previous_object(++i);
  return h;
}

status identifies_me(string str, object ob) {
  mixed h;

  if (!ob || ob == this_object()) {
    if (id(str))
      return 1;
  }
  if (ob && ob != this_object()) {
    // if we are one of the deep (or normal) components of 'ob',
    // let's identify ourselves with 'ob'
    if (((h = ob->get_components(str,1)) && member(h,this_object()) >= 0) ||
        ((h = ob->get_components(str)) && member(h,this_object()) >= 0))
      return 1;
  }
}

object get_compound();

void add_component_action(varargs mixed args) {
  apply(#'call_other,get_compound(),"component_add_action", args);
}

void add_component_action_rule(varargs mixed args) {
  apply(#'call_other,get_compound(),"component_add_action_rule", args);
}

varargs string *query_rule_verbs();

varargs void add_component_actions(string func, string family) {
  if (function_exists("query_rule_verbs",this_object()))
    filter(query_rule_verbs(family),
                 // order of arguments: func,verb,flag => swap args 0 & 1
                 sort_args(#'add_component_action,({1,0,2})),
                 func||"parse_action",1);
}

// for overloading
// In this function, calls to add_compound_action(s)() and 
// add_compound_action_rule()
void init_component() {
  add_component_actions();
}

/*
 * It would look something like this:
 * void init_component()
 * {
 *   add_compound_actions(); // actions defined by add_rule()s
 *   add_compound_action(<function>,<verb>);
 *   // ... and more of that
 *   add_compound_action_rule(<rule>,<action_id>);
 *   // ... and more of that
 * }
 */

/********************* compound-component relationship ***********************/
private mapping component_data;

status has_component_data(string id) {
  return id && component_data && member(component_data,id);
}

varargs mixed get_component_data(string id) {
  if (!id)
    return component_data;
  else if (has_component_data(id))
    return component_data[id];
}

varargs void set_component_data(mixed data, string id) {
  if (!id)
    if (mappingp(data))
      component_data = data;
    else
      raise_error("Bad argument 1 to set_component_data()\n");
  else {
    if (!component_data)
      component_data = ([]);
    component_data[id] = data;
  }
}

varargs void remove_component_data(string id) {
  if (!id)
    component_data = 0;
  else if (has_component_data(id))
    m_delete(component_data,id);
}

private static object compound;

void set_compound(object ob) {
  mixed h;

  // If we are still part of a compound, notify that compound of our removal
  if (compound && compound != ob) {
    h = compound;
    compound = 0;
    h->remove_component(this_object());
  }
  compound = ob;
}

object get_compound() {
  return compound;
}

void remove_compound() {
  set_compound(0);
}

/************************ A unique identifier for us *************************/

void set_component_name(string name) {
  set_component_data(name,"component_name");
}

// return a unique string (at least inside our compound-structure
string get_component_name() {
  return get_component_data("component_name") || object_name();
}

/************ A function to call other components of our compound ************/

mixed receive_call_component(string name, string func, varargs mixed args) {
  return
    apply(#'call_other,this_object(),func,args);
}

mixed call_component(string name, string func, varargs mixed args) {
  return
    apply(#'call_other,get_compound(),"call_component",name,func,args);
}

public void compound_save_component(status force) {
  // normally, this function does nothing
  // if overloaded by a compound that is also a component,
  // it should call the same function recursively in the components
}

// this function should recall a true value, only, if it is wise at the
// moment to save that component
// If there are call_out()s (or similar things) running, it probably isn't
// 'wise' and should only be done, if it's really necessary (e.g. If the
// player quits or something like that.
public status query_saveable() {
  // per default, a component is always saveable without problems
  return 1;
}

mixed get_component_state() {
  return get_component_data();
}

void set_component_state(mixed data) {
  set_component_data(data);
}

void notify_destruct() {
  mixed h;

  if (h = get_compound())
    h->remove_component(this_object());
}
