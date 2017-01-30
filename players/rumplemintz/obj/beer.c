#ifndef __LDMUD__
inherit "/obj/treasure";

#include <ansi.h>

void reset(status arg) {
  ::reset(arg);
  if (arg) return;

  set_short("A " + BOLD + "Rumplemintz" + NORM + " shot");
  set_long("A shot of " + BOLD + "Rumplemintz" + NORM + ".\n");
  set_weight(0);
  set_value(0);
}

void init() {
  ::init();
  add_action("drink_shot", "drink");
}

int drink_shot(string str) {
  if (!str || str != "shot") return 0;
  write("You throw back a shot of " + BOLD + "Rumplemintz" + NORM + "!\n");
  say(this_player()->query_name() + " slams a shot of " + BOLD +
      "Rumplemintz" + NORM + "!\n");
  this_player()->drink_alcohol(10);
  destruct(this_object());
  return 1;
}

#else /* We're on LDMud - Yaaayy */

#pragma strong_types

#include <persistence.h>

inherit "basic/persistence";

int full;

int id(string str) {
  if (str == "beer" && full)
    return 1;
  return str == "bottle";
}

string short() {
  if (full)
    return "bottle of beer";
  return "empty bottle";
}

string query_name() {
  if (full)
    return "beer";
  return "bottle";
}

int query_value() {
  if (!full)
    return 10;
  return 0;
}

string long() {
  return short() + ".\n";
}

void reset(int arg) {
  if (!arg)
    full = 1;
  set_persistence(PER_NO_PERSISTENCE);
}

int drink(string str) {
  if (str && str != "beer" && str != "from bottle")
    return 0;
  if (!full)
    return 0;
  if (this_player()->drink_alcohol(2))
    return 1;
  full = 0;
  write("It is really good beer!\n");
  say(this_player()->query_name() + " drinks a bottle of beer.\n");
  return 1;
}

void init() {
  add_action("drink", "drink");
}

int get() {
  return 1;
}

int query_weight() {
  return 1;
}
#endif
