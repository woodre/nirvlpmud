/*                                                                    *
 *    File: Entrance  /players/valen/area/catacombs/rooms/entrance.c  *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 Valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/09                                      *
 *    Notes:            Area Entrance                                 *
 *                                                                    *
 *                                                                    *
 *    Change History: spelling correction/description addition        *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIBLK+"Catacombs Entrance"+NORM;
  long_desc =
  HIBLK+"  The entrance of the catacombs has been deserted\n\
  by the Magi a long time ago and is very small and hard to\n\
  see with the lack of light. There is a torch on the wall\n\
  lightning the entrance way. The torch is magical lite. The\n\
  Magi of this isle were powerful indeed. The spell on the\n\
  torch is still working from when the Magi used to walk this\n\
  island. The ceiling once was graceful from its elegant\n\
  structure design. But now the ceiling has cracks and roots\n\
  have grown into those cracks. The ground is scattered with\n\
  pebbles and dust. At the end of the entrance you can see a\n\
  stairway. The stairway looks to be craved into the earth\n\
  itself. The stairway has a filthy arched ceiling and leads\n\
  in a circular direction down."+NORM+"\n";
  
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
    "wall", 
    "The walls are gray and made of bricked stones",
    "stones", 
    "The bricked stones are old looking",
    "stairway", 
    "The stairway is made of bricked stones and descends into darkness",
    "roots",
    "The roots are starting to replace the ceiling",
    "ceiling",
    "The ceiling is still holding together after all this time",
  });
  dest_dir =
  ({
    "/room/south/sislnd1.c",                               "out",
    "/players/valen/area/catacombs/rooms/dungeonb2.c",     "down",
  });
 
}
