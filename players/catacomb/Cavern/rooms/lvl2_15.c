#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The river of lava surrounds the area making an island of heat.\n"+
  "The magma to the west prevents passage in that direction.  Cracks\n"+
  "form on the ground giving off an orange glow with smoke barreling\n"+
  "up choking all who pass.\n"); 

  items = ({
    "river",
    "The river of lava surrounds the island",
    "lava",
    "The river of lava surrounds the island", 
    "magma",
    "A large hole of magma blocks passage to the west", 
    "cracks",
    "Small cracks form underneath your feet and give off an orange glow",
    "crack",
    "Small cracks form underneath your feet and give off an orange glow",
    "smoke",
    "Smoke barrels out of the cracks in the ground",
    "ground",
    "Small cracks form underneath your feet and give off an orange glow",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_13.c","northwest",
    "/players/catacomb/Cavern/rooms/lvl2_17.c","south",
  });
}
