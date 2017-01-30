/*
 *      File:                 /players/star/hotel/rooms/up_hall4.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/11/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "The Upstairs Hallway";
  long_desc = 
    "   The upstairs hallway of the Overlook Hotel is carpeted with a\n"+
    "luxuriously thick blue rug that has a squiggly black pattern.  The\n"+
    "walls are painted white, and here and there along them are lights\n"+
    "about five feet above the floor.  There is an old-fashioned fire\n"+
    "extinguisher on the wall here, just opposite a door with a metal\n"+
    "number 213 gleaming in the light.\n";

  items =
  ({
    "hallway",
    "The hall extends to the east and west from here",
    "rug",
    "The rug is blue, with a pattern of black squiggles",
    "pattern",
    "The pattern is just black squiggles, nothing special",
    "walls",
    "The walls are white",
    "lights",
    "The lights are replicas of old-fashioned gas lamps",
    "floor",
    "The floor is covered by the blue rug",
    "extinguisher",
    "The fire extinguisher is simply a long hose folded in a stack inside\n"+
    "its holder.  It can't possibly be in line with fire codes",
    "fire extinguisher",
    "The fire extinguisher is simply a long hose folded in a stack inside\n"+
    "its holder.  It can't possibly be in line with fire codes",
    "door",
    "The door is wooden, brown, has the number 213 on it, and can be\n"+
    "entered... if you dare",
    "number",
    "The number looks like it is made out of brass",
  });
  dest_dir =
  ({
    HOTEL+"rooms/up_hall3.c",     "west",
    HOTEL+"rooms/up_hall5.c",     "east",
  });
}

void init()
{
   ::init();
   add_action("cmd_enter","enter");
}

int cmd_enter(string str)
{
  if(!str)
  {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "door" && str != "213" && str != "room" && str != "room 213")
  {
    notify_fail("You can only \"enter\" the \"door\".\n");
    return 0;
  }

    write("You enter room 213.\n");
    this_player()->move_player("through the door#/players/star/hotel/rooms/213.c");

    return 1;
}
