/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/rooms/dungeona5.c    *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            dungeon room a 5                              *
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
    move_object(clone_object("/players/valen/area/catacombs/mobs/imp.c"), this_object());
  }
  short_desc = HIBLK+"<Catacombs of the Magi>"+NORM;
  long_desc =
  HIBLK+"  The catacombs storage is dark. The shelves are empty\n\
except for the spider webs.  The ground is covered with dust.\n\
The arched ceiling is is covered with weeds. The ground is dusty\n\
and covered with pebbles. A old wooden door to the east."+NORM+"\n";

  items =
  ({
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
    "weeds",
    "Just so some weeds",
    "door",
    "The old wooden door is to the east",
    "shelves",
    "The shelves are empty",
    "spider webs",
    "The spider webs make some complex designs",
  });
  dest_dir =
  ({
    "/players/valen/area/catacombs/rooms/dungeonb5.c",     "east",
   
  });
 
}
