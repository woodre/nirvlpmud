/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeonb4.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room b 4                              *
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
  HIBLK+"  This part of the catacombs has been closed off for a\n\
  long time. The catacombs have become a very small path. The\n\
  arched ceiling is only 8 feet high and the path is only 4 feet\n\
  wide. Only a few torches are on the hanging on both sides of the\n\
  path. The stoned walls are covered with a green moss."+NORM+"\n";

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
    "pillars", 
    "A connecting support beam from the floor to the ceiling", 
    "wall",
    "The wall is made from stoned bricks",
    "moss",
    "Just a green moss",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb3.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeonb5.c",     "south",
  });
}