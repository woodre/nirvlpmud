/*
// /bin/_heal.c
//
// Daemonized by Shadowhawk.
*/

#include <security.h>

#pragma strict_types
#pragma save_types

int
cmd_heal(string name) {
  object ob;

  if (!name || (int)this_player()->query_level() < DAMAGE)
    return 0;
  name = lower_case(name);
  ob = find_player(name);
  if (!ob)
    ob = find_living(name);
  if (!ob) {
    write("No such person is playing now.\n");
    return 1;
  }
  ob->heal_self(100000);
  if ((int)this_player()->query_invis() < INVIS_ACTION)
    tell_object(ob, "You are healed by " + this_player()->query_name() +
      ".\n");
  write("You healed " + capitalize(name) + ".\n");
  return 1;
}
