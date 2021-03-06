/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hall13.c    *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           12/31/06                                      *
 *    Notes:                                                          *
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
  if( !present("corporal", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/corporal.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"HALL"+NORM;
  long_desc =
"    "+HIC+"~ HALL LEVEL 26 ~"+NORM+"\n\
"+CYN+"  This is a deep underground facility. All sides of the room are\n\
made of three feet thick concrete. Many pipes and wires run along\n\
the ceiling and air is pumped down from the surface. This facility\n\
is well secured. The hallway leads to many rooms."+NORM+"\n";

  items =
  ({
    "facility",
    "underground building",
    "room",
    "its solid concrete",
    "concrete",
    "man maid solid rock",
    "pipes",
    "various sizes and colors",
    "wires",
    "various sizes and color",
    "ceiling",
    "Its full of pipes and wires",
    "surface",
    "Earth, what you walk on",
    "hallway",
    "A long corridor connecting rooms",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall12", "north",
	"/players/angel/area/stargate/room/pg",     "east",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }