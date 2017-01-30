#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Staircase");
  set_long("\
Dojo - Staircase\n\
A spiral staircase leads down to the Shomen.\n\
To the north, you see the Emperor's Chambers, surrounded by a\n\
shimmering force field. You hear the clash of weapons coming\n\
from the south, and the hiss of a forge to the east.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_gc","north",
    ROOMDIR+"dojo_armory","east",
    ROOMDIR+"dojo_arena","south",
    ROOMDIR+"dojo_personal","west",
    ROOMDIR+"dojo_shomen","down",
  });
}

init()
{
  ::init();
  add_action("cmd_north","north");
}

cmd_north()
{
  if(this_player()->query_guild_rank() != 11)
  {
    write("You cannot enter the Emperor's chambers.\n");
    return 1;
  }
  return 0;
}
