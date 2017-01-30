#ifndef __LDMUD__ /* New code below - Rumplemintz */
int full;

id(str) {
    if (str == "beer" && full)
  return 1;
    return str == "bottle";
}

short() {
    if (full)
  return "bottle of beer";
    return "empty bottle";
}

/* The shop only buys empty bottles ! */

query_value()
{
    if (!full) return 10;
    return 0;
}

long() {
    write(short() + ".\n");
}

reset(arg) {
    if (arg)
        return;
    full = 1;
}

drink(str)
{
    if (str && str != "beer" && str != "from bottle")
  return 0;
    if (!full)
  return 0;
    if (!call_other(this_player(), "drink_alcohol", 2))
  return 1;
    full = 0;
    write("It is really good beer!\n");
    say(call_other(this_player(), "query_name", 0) +
  " drinks a bottle of beer.\n");
    return 1;
}

init() {
    add_action("drink"); add_verb("drink");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
#else
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

/* The shop only buys empty bottles ! */
int query_value() {
  if (!full)
    return 10;
  return 0;
}

string long() {
  return short() + ".\n";
}

void reset(int arg) {
  if (!arg) {
    full = 1;
  }
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

