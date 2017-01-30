#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The river of lava to the north trudges along at a slow pace with flames\n"+
  "errupting every few feet.  A large magma filled hole is lying to the south.\n"+
  "Adventurers must travel fast within this area or they may succumb to the \n"+
  "fumes.  The air is very heavy with the heat emitting from both the fire and \n"+
  "boiling magma.\n"); 

  items = ({
    "river",
    "The river passes slowly by to the north",
    "lava",
    "The lava lurches by shooting flames up as it passes", 
    "flame",
    "The flames shoot up under the bridge to the north", 
    "flames",
    "The flames shoot up under the bridge to the north",
    "magma",
    "The magma sits calmly at the bottom of the hole",
    "hole",
    "A large hole filled with magma"
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_bridge.c","bridge",
    "/players/catacomb/Cavern/rooms/lvl2_14.c","southwest",
    "/players/catacomb/Cavern/rooms/lvl2_15.c","southeast"
  });
}
