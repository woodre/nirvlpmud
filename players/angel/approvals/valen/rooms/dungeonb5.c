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
  short_desc = HIBLK+"Catacombs of the Magi"+NORM;
  long_desc =
  HIBLK+"  The catacomb path has come to a end. The arched\n\
  ceiling is lined with cracks and weeds have filled the\n\
  cracks. The floor is completely covered with dirt and\n\
  pebbles. There is an old wooden door on the western wall\n\
  with a single"+RED+"torch"+HIBLK+"on the opposite wall."+NORM+"\n";

  items =
  ({
    "torch", 
    "The torch is secured to the wall and you can twist it",
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
    "Just so some weeds",
    "door",
    "The old wooden door is locked",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb4.c",    "north",
    "/players/valen/area/catacombs/rooms/dungeona5.c",    "west",
  });
}