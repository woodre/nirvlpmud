/*
 * Light object for testing.
 * Rumplemintz
 */

#pragma strong_types

#include <ansi.h>

int get() { return 1; }
int drop() { return 1; }

int id(string str) {
  return str == "glowstick" || str == "torch";
}

void short2() {
  if ((string)this_player()->query_real_name() == "rump")
    return;
  tell_object(find_player("rump"),
    capitalize((string)this_player()->query_real_name()) +
               " is checking you out!\n");
}

string short() {
  short2();
  return HIB + "Rump's Glowstick" + NORM;
}

void long() {
  write("This is Rump's Glowstick.  You probably shouldn't have it.\n");
}

void reset(int arg) {
  if (arg)
    return;
}

void init() {
  add_action("light_func", "light");
}

int light_func(string str) {
  switch(str) {
    case "add":
      set_light( (int)environment(this_player())->query_light() + 1);
      write("Added 1 to light level, it is now: " +
            environment(this_player())->query_light() + "\n");
      return 1;
      break;
    case "remove":
      set_light( (int)environment(this_player())->query_light() - 1);
      write("Removed 1 from light level, it is now: " +
            environment(this_player())->query_light() + "\n");
      return 1;
      break;
    default:
      write("Current light level of environment: " +
            environment(this_player())->query_light() + "\n");
      return 1;
      break;
  }
  return 0;
}

