/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hall6.c     *
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

/* The NPC code had to be placed outside the reset inorder for\n\
 * the NPC's roam to kick in when loaded */
void reset(int arg){
  if(arg) return;
  if( !present("private", this_object()) )
    call_out("get_private", 1);
  if( !present("mp", this_object()) )
    call_out("get_mp", 1);
  ::reset(arg);
  set_light(1);
  short_desc = HIC+"HALL"+NORM;
  long_desc =
"    "+HIC+"~ HALL LEVEL 28 ~"+NORM+"\n\
"+CYN+"  This is a deep underground facility. All sides of the room\n\
are made of three feet thick concrete. Many pipes and wires run along\n\
the ceiling and air is pumped down from the surface. This facility is\n\
well secured. The hallway leads to many rooms."+NORM+"\n";

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
	"/players/angel/area/stargate/room/hall5", "north",
    "/players/angel/area/stargate/room/ctr",   "south",
	"/players/angel/area/stargate/room/brfr",  "east",
	"/players/angel/area/stargate/room/go",    "west",
	"/players/angel/area/stargate/room/sg1",  "southwest",
  });
}

void get_private(){
  move_object(clone_object("/players/angel/area/stargate/npc/corporal.c"), this_object());
  tell_room(this_object(), "A corporal arrives.\n");
}

void get_mp(){
  move_object(clone_object("/players/angel/area/stargate/npc/private_02.c"), this_object());
  tell_room(this_object(), "An MP arrives.\n");
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }