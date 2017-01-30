#include <ansi.h>
#include "../lib/guild_defs.h"

#define ROOMDIR "/players/vertebraker/classic/undead/room/"

status id(string str)
{
  return (str == "castle of eternal night" || str == "castle");
}

string short()
{
  return CEN;
}

void init()
{
  add_action("cmd_enter", "enter");
  add_action("cmd_in",    "in");
}

void long()
{
  write("\
A long buried castle of Nirvana, recently uncovered by Ryllian\n\
archeologists digging in this sector. Despite its burial, it\n\
seems remarkably well-kept. An aura of mystery and danger\n\
surrounds it. Something dark lies deep within.\n");
}

int cmd_enter(string str)
{
  if(!str || !id(str))
  {
    notify_fail("You may only enter the castle.\n");
    return 0;
  }
  write("\n\n\t\tYou descend into the gloomy depths of the " + HIK +
  "dark castle" + NORM + ".\n\n");
  say((string)TP->QN + " enters the " + HIK + "dark castle" + NORM + ".\n");
  TP->move_player("X#" + ROOMDIR + "f1");
  return 1;
}

status is_castle() { return 1; }

int cmd_in(string str)
{
  if(str) return 0;
  return cmd_enter("dark castle");
}
