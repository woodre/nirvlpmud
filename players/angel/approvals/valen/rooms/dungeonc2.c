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
  set_light(1);
  short_desc = HIBLK+"Catacombs of the Magi"+NORM;
  long_desc =
  HIBLK+"  This part of the catacomb is much smaller than the\n\
  atrium. Even the pillars here are much smaller. There are\n\
  some torches hanging on the pillars. The ceiling is now\n\
  visible with roots dangling from it. A flowing fountain is\n\
  sculpted into the stone wall."+NORM+"\n";
  
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
    "fountain",
    "The fountain is running with water still.  The water is\n"+
    "looks clean to drink from. At the spout of water the water\n"+
    "is coming from is a well engraved shape of a lion's head.\n"+
    "The water is coming from the lion's"+RED+" mouth"+NORM+"\n",
    "mouth",
    "A button is hidden in the spout",   
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb2.c",     "west",
    "/players/valen/area/catacombs/rooms/dungeonc1.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeond2.c",     "enter path",
    "/players/valen/area/catacombs/rooms/dungeonc3.c",     "south",
  });
 
}
