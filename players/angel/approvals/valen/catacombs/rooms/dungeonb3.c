/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeonb3.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room b 3                              *
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
  if( !present("vermin", this_object()) )
  {
    move_object(clone_object("/players/valen/area/catacombs/mobs/vermin.c"), this_object());
  }
  short_desc = HIBLK+"<Catacombs of the Magi>"+NORM;
  long_desc =
  HIBLK+" This part of the catacomb is much smaller than the atrium.\n\
Even the pillars here are much smaller. There are some torches\n\
hanging on the pillars. The ceiling is now visible with roots\n\
dangling from it. There is a old iron gate to the south. A\n\
"+NORM+BMAG+"bronze lock"+NORM+HIBLK+" is beside the gate on the wall."+NORM+"\n";
  
  items =
  ({
    "catacomb",
    "The catacomb path goes in three directions. East, West, and North",
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
    "gate",
    "A old"+HIBLK+" iron gate"+NORM+" that someone could enter",
    "lock",
    "A bronze lock with a emblem of a crossed "+BLUE+"Sword"+NORM+" and "+HIW+"Feather"+NORM+" at\n"+
    "its base. A adventure could unlock the gate if they have the key with the\n"+
    "emblem on it.\n",
    "bronze lock",
    "A bronze lock with a emblem of a crossed "+BLUE+"Sword"+NORM+" and "+HIW+"Feather"+NORM+" at\n"+
    "its base. A adventure could unlock the gate if they have the key with the\n"+
    "emblem on it.\n",
       
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeona3.c",     "west",
    "/players/valen/area/catacombs/rooms/dungeonb2.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeonc3.c",     "east",
  });
}

int gate1;

init()
{
  ::init();
  add_action("cmd_listen","listen");
  add_action("unlock","unlock");
  add_action("enter","enter");
}

unlock(str)
{
  if(str == "gate")
  {
  	if(gate1 == 0)
	{
  	  if (present("valen_key",this_player()))
      {
        gate1 = 1;
        write("The bronze key fits into the lock and turns perfectly\n"+
        "The gate begins to rise slowly with a metallic clicking\n"+
        "A adventurer could"+RED+" enter gate"+NORM+" now\n");
      }
      else write("You don't have the right key!\n");
      return 1;
    }
    else write("The gate is already open.\n");
    return 1;
  }
  else write("Unlock what?\n");
  return 1;
}

cmd_listen()
{
  write("You can hear something"+CYN+" cackling "+NORM+"from beyond the gate\n");
  return 1;
}

enter(str)
{
  if(str =="gate")
  {
	if (gate1 == 1)
    {
      say(capitalize(this_player()->query_name())+" enters the gate.\n");
      this_player()->move_player("enters the gate#/players/valen/area/catacombs/rooms/dungeonb4.c");
      say(capitalize(this_player()->query_name())+ " arrives.\n");
    }
    else write("The old"+HIBLK+" iron gate"+NORM+" is locked.\n");
    return 1;
  }
  else write("Enter what?\n");
  return 1;
}