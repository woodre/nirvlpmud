#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  In the center of the walkway is a portal that stopped rotating long\n"+
  "ago.  The Durkor talk of some sort of ruler that was in this area of\n"+
  "their caverns.  The cracks widen here so an adventurer must be quick\n"+
  "if they want to be able to activate the portal before the river below\n"+
  "swallows the island whole.\n"); 

  items = ({
    "walkway",
    "The cracks widen quickly making it hard to stand here for very long",
    "portal",
    "A dark orange vortex that quit swirling long ago", 
    "vortex",
    "There has to be someone who knows how to start the portal going again", 
    "cracks",
    "The cracks become very large in areas",
    "crack",
    "As the crack widens, the rocks falling are consumed by the flames",
    "river",
    "The river underneath the island quickly rises devouring the entire island",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_15.c","north",
    "/players/catacomb/Cavern/rooms/lvl2_16.c","west",
  });
}
