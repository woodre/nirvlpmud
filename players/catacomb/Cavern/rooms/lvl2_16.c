#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The cracks in the ground grow to large proportions.  The glow\n"+
  "coming from underneath them is very bright.  Smoke eminates from\n"+
  "each of the cracks making it very difficult to navigate the narrow\n"+
  "walkways of the island.\n"); 

  items = ({
    "cracks",
    "The cracks are very large forcing you to almost jump over each of them",
    "crack",
    "The cracks are very large forcing you to almost jump over each of them", 
    "ground",
    "The cracks are very large forcing you to almost jump over each of them", 
    "glow",
    "The glow from the cracks is a bright orange",
    "smoke",
    "The smoke barrels out of each crack making vision difficult",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_14.c","north",
    "/players/catacomb/Cavern/rooms/lvl2_17.c","east",
  });
}
