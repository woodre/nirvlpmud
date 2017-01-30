#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The rocks are scattered throughout the cavern, forcing adventurers\n"+
  "to try and climb around them to get through.  With each rock comes \n"+
  "another chance of a Durkor attack.  The Durkor are known for their\n"+
  "ambushes of lone travellers.  Sounds seem to jump out of the walls,\n"+
  "making it seem as if something is watching.\n"); 

  items = ({
    "rocks",
    "The rocks provide excellent cover for the Durkor assassins",
    "rock",
    "The rocks provide excellent cover for the Durkor assassins",
    "cavern",
    "Small noises echo off the many rocks throughout the cavern",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_9.c","southeast",
    "/players/catacomb/Cavern/rooms/lvl2_11.c","climb"
  });
if(!present("scout"))
 move_object(clone_object("/players/catacomb/Cavern/mobs/durkorScout.c"),
	    this_object());
}
