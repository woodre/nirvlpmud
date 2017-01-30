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
  short_desc = HIBLK+"Catacombs of the Magi"+NORM;
  long_desc =
  HIBLK+" This part of the catacomb is much smaller than\n\
  the atrium. Even the pillars here are much smaller. There\n\
  are some torches hanging on the pillars. The ceiling is now\n\
  visible with roots dangling from it. There is a old iron gate\n\
  to the south.  A bronze lock is beside the gate on the wall."+NORM+"\n";
  
  items =
  ({
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
    "The old iron gate is locked",
    "lock",
    "A bronze lock with a emblem of a sword and feather at its base",   
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeona3.c",     "west",
    "/players/valen/area/catacombs/rooms/dungeonb2.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeonc3.c",     "east",
    "/players/valen/area/catacombs/rooms/dungeonb4.c",     "south",
  });
}

init() {
  ::init();
  add_action("cmd_listen","listen");
}

cmd_listen(str) {
  write("You can hear something cackling from beyond the gate\n");
  return 1;
}