/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeonb5.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room b 5                              *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIBLK+"<Catacombs of the Magi>"+NORM;
  long_desc =
  HIBLK+"  The catacomb path has come to a end. The arched ceiling is\n\
lined with cracks and weeds have filled the cracks. The floor\n\
is completely covered with dirt and pebbles. There is an old\n\
wooden door on the western wall with a single"+RED+" torch"+HIBLK+" on the\n\
opposite wall."+NORM+"\n";

  items =
  ({
    "catacomb",
    "The catacomb path goes in one direction. North",
    "ceiling",
    "The arched ceiling is lined with cracks and weeds",
    "torch", 
    "The torch is secured to the wall and you could"+RED+" twist"+NORM+" the "+RED+"torch"+NORM+"\n",
    "dust", 
    "The dust fills the air and covers the floor",
    "pebbles", 
    "Pebbles are scattered everywhere on the floor",
    "floor", 
    "The floor is covered with pebbles and dust",
    "stones", 
    "The bricked stones are old looking",
    "pillars", 
    "A connecting support beam from the floor to the ceiling", 
    "wall",
    "The wall is made from stoned bricks",
    "weeds",
    "Just some weeds",
    "door",
    "A very old"+HIBLK+" wooden door"+NORM+"\n",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb4.c",    "north",
  });
}

int door1;

init() 
{ ::init();
  add_action("twist","twist");
  add_action("enter","enter");
  add_action("open","open");
}

twist(str)
{ 
  if(str == "torch")
  {
    if(door1 == 0)
    {
	  door1 = 1;
      write("  The old"+HIBLK+" wooden door"+NORM+" just sounded with a metallic click\n"+
      "The old "+HIBLK+" wooden door"+NORM+" swings open. Now someone could "+RED+" enter"+NORM+" the "+RED+"door"+NORM+"\n");
      return 1;
    }
    else write("The"+RED+" torch"+NORM+" has already been twisted.\n");
    return 1;
  }
  else write("Twist what?\n");
  return 1;
}

enter(str)
{
  if(str == "door")
  {
	if (door1 == 1)
    {
      say(capitalize(this_player()->query_name())+" enters the old"+HIBLK+" wooden door"+NORM+"\n");
      this_player()->move_player(" opened the"+HIBLK+" wooden door"+NORM+" and entered the door#/players/valen/area/catacombs/rooms/dungeona5.c");
      say(capitalize(this_player()->query_name())+ " arrives.\n");
    }
    else write ("The old"+HIBLK+" wooden door"+NORM+" is"+CYN+" closed."+NORM+"\n");
    return 1;
  }
  else write("Enter what?\n");
  return 1;
}

open(str)
{
  if(str == "door")
  {
	  if(door1 == 1)
	  {
	    write("The old"+HIBLK+" wooden door"+NORM+" is already open. Someone could"+RED+" enter door"+NORM+"\n");
	    return 1;
      }
      else write("The old"+HIBLK+" wooden door"+NORM+" is locked.\n");
      return 1;
  }
  else write("Open what?\n");
  return 1;
}
