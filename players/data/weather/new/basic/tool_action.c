/****************************************************************************
    /basic/tool_action.c -- an abstract class for tool actions -- Ugh 
*****************************************************************************/

// This class in itself doesn't actually _do_ anything, except
// say what functions could/should be overriden by a tool
// implementing one or more tool-actions.

// If you add a tool-action to an object, don't forget to call
// these functions in the tool-action and other inherited classes
// that define them.

// add plannable actions here
void configure() { }

// add actual actions here
void init_actions() { }

// make a concrete action mapping from an abstract one
mapping build_complete_action(mapping action, mapping args) {
  return 0;  // Coogan, 27-Mar-2011
}

// build an action event from a concrete action mapping
mapping build_action_event(mapping action) {
  return 0;  // Coogan, 27-Mar-2011
}

// return failure message if action is not possible to start
mixed query_action_impossible(mapping action) {
  return 0;  // Coogan, 27-Mar-2011
}

// return failure message if action is not possible to continue
mixed query_running_action_impossible(mapping action) {
  return 0;  // Coogan, 27-Mar-2011
}

// FIXME: this should be moved elsewhere
varargs object find_hit_location(object ob, string id, object hit_by) {
  return ob->get_hit_location(hit_by,id) || ob;
}

