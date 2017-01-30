#include "../lib/guild_defs.h"

#include <ansi.h>

string dest;

string short() { return HIK + "A swirling black portal" + NORM; }

void init()
{
  add_action("cmd_enter", "enter");
  add_action("cmd_in","in");
}

status id(string str)
{
  return (str =="portal"||str=="black portal");
}

int cmd_enter(string str)
{
  if(!str)
  {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("\n\tYou step into the " + HIK + "swirling black portal" + NORM + "...\n");
  say((string)TP->QN + " steps into the " + HIK + "swirling black portal" + NORM + "...\n");
  write("\n\n\n\t\tYou feel like you're falling...\n\n");
  if(!dest) dest = "room/church";
  TP->move_player("X#" + dest);
  return 1;
}

void long()
{
  write("\n\
You cannot see beyond the swirling layers of black energy.\n\
You fear what lies at the unknown destination.\n");
}
