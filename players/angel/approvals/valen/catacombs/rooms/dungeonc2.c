/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeonc2.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room c 2                              *
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
  if( !present("vermin", this_object()) )
  {
    move_object(clone_object("/players/valen/area/catacombs/mobs/vermin.c"), this_object());
  }
  set_light(1);
  short_desc = HIBLK+"<Catacombs of the Magi>"+NORM;
  long_desc =
  HIBLK+"  This part of the catacomb is much smaller than the atrium.\n\
Even the pillars here are much smaller. There are some torches\n\
hanging on the pillars. The ceiling is now visible with roots\n\
dangling from it. A "+WHT+HBBLU+"flowing fountain"+NORM+HIBLK+" is sculpted into the\n\
stone wall."+NORM+"\n";
  
  items =
  ({
    "catacomb",
    "The catacomb path goes in three directions. East, West and South",
    "ceiling",
    "The ceiling is falling apart and roots cover the ceiling",
    "torch", 
    "The torch is secured to the wall and cannot be removed",
    "dust", 
    "The dust fills the air and covers the floor",
    "pebbles", 
    "Pebbles are scattered everywhere on the floor",
    "floor", 
    "The floor is covered with pebbles and dust",
    "stones", 
    "The bricked stones are old looking",
    "wall",
    "The wall is made from stoned bricks",
    "fountain",
    "The fountain is running with water still.  The water is\n"+
    "looks clean to drink from. At the spout of water the water\n"+
    "is coming from is a well engraved shape of a lion's head.\n"+
    "The water is coming from the lion's"+RED+" mouth"+NORM+"\n",
    "flowing fountain",
    "The fountain is running with water still.  The water is\n"+
    "looks clean to drink from. At the spout of water the water\n"+
    "is coming from is a well engraved shape of a lion's head.\n"+
    "The water is coming from the lion's"+RED+" mouth"+NORM+"\n",
    "mouth",
    "A button is hidden in the spout. Who knows what would happen if\n"+
    "someone would"+RED+" push button"+NORM+"\n",   
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb2.c",     "west",
    "/players/valen/area/catacombs/rooms/dungeonc1.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeonc3.c",     "south",
  });
}

int path1;

init() 
{ ::init();
  add_action("push","push");
  add_action("enter","enter");
  add_action("drink","drink");
}

push(str)
{ 
  if(str == "button")
  {
	if(path1 == 0)
    {	
      write("A hidden path appears in the stone wall.\n"+
      "A adventurer could"+RED+" enter path."+NORM+" But\n"+
      "the path will close behind the adventurer\n");
      path1 = 1;
      return 1;
    }
    else write("The button has already been pushed.\n");
    return 1;
  }
  else write("Push what?\n");
  return 1;
}

enter(str)
{
  if(str == "path")
  {
	if (path1 == 1)
    {
      say(capitalize(this_player()->query_name())+" enters the path and the path begins to close.\n");
      this_player()->move_player("enters the path#/players/valen/area/catacombs/rooms/dungeond2.c");
      say(capitalize(this_player()->query_name())+ "arrives.\n");
      path1 = 0;
    }
    else write("There is no path here to enter.\n");
    return 1;
  }
  else write("Enter what?\n");
  return 1;
}

drink(str)
{
  if(str == "water")
  {
    write("You try to drink the water. But, the water dissappears before it reaches\n"+
    "your lips!\n");
  }
  else write("Drink what?\n");
  return 1;
}
