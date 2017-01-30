/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeonb2.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room b 2                              *
 *                                                                    *
 *                                                                    *
 *    Change History:   spelling correction and description addition  *
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
  HIBLK+"  This chamber is the atrium of the catacombs. The atrium is\n\
massive. The vast amount of empty space can be seen in every\n\
every direction. There are many pillars supporting this\n\
catacomb. Pillars extent from the ground to the darkness\n\
above. There are many torches on the pillars barely lighting\n\
the catacombs. The ground is scattered with pebbles and dust.\n\
A stairway that leads up in a circular direction."+NORM+"\n";

  items =
  ({
    "atrium",
	"The atrium is huge and dark",
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
    "stairway",
    "The stairway is made of bricked stones and ascends to the surface",
    "pillars",
    "The pillars are massive in size",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/entrance.c",      "up",
    "/players/valen/area/catacombs/rooms/dungeonb1.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeonc2.c",     "east",
    "/players/valen/area/catacombs/rooms/dungeonb3.c",     "south",
    "/players/valen/area/catacombs/rooms/dungeona2.c",     "west",
  });
}