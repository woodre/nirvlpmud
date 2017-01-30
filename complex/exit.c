/*
 * complex/exit.c (C) Ugh Nov-1994, written for Tubmud
 *
 */

#pragma strong_types

#include <grammar.h>
#include <prop/item.h>
#include <server.h>

inherit "complex/item";

private string direction = "nowhere";
private string door_type;  // Coogan, 03-Mar-2006

string query_direction();

void create() {
  item::create();
  set_property(P_NOT_PORTABLE);
}

// Ugh Aug-7-1995 -- usage of the new action-system
void init() {
  item::init();
  add_action_rule("leave through <object>", "leave");
  add_action_error_message("leave", "Leave through what?\n");

  add_action_rule("go through <object>", "leave");
  add_action_rule("go <text>", "go_direction");
  add_action_error_message("go", "Go through what or where?\n");

  add_action_rule("pass <object>", "leave");
  add_action_rule("pass through <object>", "leave");
  add_action_error_message("pass", "Pass what?\n");

  add_action_rule("enter <object>", "leave");
  add_action_error_message("enter", "Enter what?\n");
}

// next two functions by Coogan, 03-Mar-2006
void set_door_type(string type) {
  door_type = type;
}

string query_door_type() {
  return door_type;
}

void add_door(mixed to) {
  return SE_DOORS->add_door(this_object(), to, query_door_type());
}

object get_other_door() {
  return SE_DOORS->get_other_door(this_object());
}

object get_destination() {
  return SE_DOORS->get_destination(this_object());
}

void remove_door() {
  return SE_DOORS->remove_door(this_object());
}

void notify_destruct(object ob) {
  if (environment()) 
    environment()->remove_exit(query_direction());
}

status prevent_move(object from, mixed to) {  // mixed, Coogan, 29-Sep-2010
  // if it was moved once, never let it move again
  return !!environment();
}

void notify_move(object from, object to) {
  if (from) 
    remove_door();
}

string query_direction() {
  return direction;
}

void set_direction(string dir) {
  if (environment())
    environment()->remove_exit(query_direction());
  direction = dir;
}

varargs void set_door_exit(mixed dest, string dir, mixed hook, 
              mixed flags, mixed exit_str) {
  if (!environment()) 
    return;
  remove_door();
  add_door(dest);
  if (hook && stringp(hook))
    hook = symbol_function(hook, previous_object());
  if (dir && stringp(dir)) {
    set_direction(dir);
    // default-move-hook added by Ugh Jun-6-1995
    environment()->add_exit(#'get_destination, 
                            query_direction(), 
                            hook, 
                            flags, 
                            exit_str);
  }
}

static status pass_door(string str) {
  if (str) {
    notify_fail(capitalize(query_direction()) + " " + str + "?\n");
    return 0;
  }
  environment()->use_exit(query_direction());
  return 1;
}

status do_action(string verb, mapping args) {
  object other_door;
  switch (verb) {
  case "leave":
    // test for args[G_OBJECT] added by Ugh Jan-21-1997
    if (args[G_OBJECT] && 
        (args[G_OBJECT] != this_object() ||
        query_fakeitem_id(args[G_OBJECT,1])))
      break;
    return pass_door(0);
    break;
  case "go_direction":
    // lower_case added by Ugh Jun-6-1995
    if (lower_case(args[G_TEXT]) == query_direction()) 
      return pass_door(0);
    break;
  default: 
    break;
  }
  return 0;
}

