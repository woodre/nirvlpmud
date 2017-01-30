/*                                                                    *
 *    File: Entrance  /players/valen/catacombs/entrance.c             *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 Valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/09                                      *
 *    Notes:            Area Entrance                                 *
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
  short_desc = BLK+"Catacombs Entrance"+NORM;
  long_desc =
BLK+"  The Entrance of the Catacombs has been deserted by the Magi along time ago.\n\
There is a"+RED+"torch"+BLK+" on the wall lightning the entrance way. The ground is\n\
scattered with pebbles and dust. A stairwell leads down."+NORM+"\n";

  items =
  ({
    "torch",
    "The torch is magical lite",
    "dust",
    "The dust fills the air and covers the floor",
    "pebbles",
    "Pebbles are scattered everyone on the floor",
    "floor",
    "The floor is covered with pebbles and dust",
    "wall",
    "The walls are gray and made of bricked stones",
    "stones",
    "The bricked stones are old looking",
    "stairwell",
    "The stairwell is made of bricked stones and descend into darkness",
  });
  dest_dir =
  ({
    "/room/south/sislnd1.c",                    "out",
    "/players/valen/catacombs/dungeonb2.c",     "down",
  });
}