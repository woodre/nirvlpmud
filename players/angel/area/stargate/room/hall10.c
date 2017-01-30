/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hall10.c    *
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
  if( !present("sergeant", this_object()) )
    move_object(clone_object("/players/angel/area/stargate/npc/sergeant.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = HIC+"HALL"+NORM;
  long_desc =
"    "+HIC+"~ HALL LEVEL 27 ~"+NORM+"\n\
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
    "earth, what you walk on",
    "hallway",
    "a long corridor connecting rooms",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall9", "north",
	"/players/angel/area/stargate/room/hc3",   "east",
	"/players/angel/area/stargate/room/hc2",   "west",
  });
}

init(){
  ::init();
    add_action("stop","east");
    add_action("stop","west");
    this_player()->set_fight_area();
   }

   stop() {
    if(present("sergeant", environment(this_player())))
      {write("The sergeant says: You are not allowed beyond this point.\n");
      say(this_player()->query_name()+" you not allowed beyond this point.\n");
        return 1;
}}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }