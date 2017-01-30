/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeonc1.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room c 1                              *
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
  HIBLK+"  This part of the catacomb is much smaller than the atrium.\n\
Even the pillars here are much smaller. There are few torches\n\
hanging on the pillars. The ceiling is now visible with roots\n\
dangling from it. There is a huge arched gateway place along\n\
the wall here. There appears to be some type of glowing runes\n\
on the arched gateway."+NORM+"\n";

  items =
  ({
    "catacomb",
    "The catacomb path goes in two directions. West and South",
    "ceiling",
    "The ceiling has cracks with weeds filling those cracks",
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
    "pillars",
    "A connecting support beam from the floor to the ceiling",
    "wall",
    "The wall is made from stoned bricks",
    "gateway",
    "The arched gateway is made from some type of unknown stone",
    "runes",
    "You cannot decipher the runes on the gateway",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb1.c",     "west",
    "/players/valen/area/catacombs/rooms/dungeonc2.c",     "south",
  });
}