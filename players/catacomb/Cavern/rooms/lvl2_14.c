#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The heat is very bad making breathing extremely difficult.  The \n"+
  "heat eminates from the magma boiling in the chasm to the east.  The \n"+
  "floor begins melting under the tremendous heat.  The cracks below"+
  "show the fiery river underneath the small island.  \n"); 

  items = ({
    "hole",
    "Heat eminates from the magma filled hole",
    "magma",
    "The heat eminates from the magma", 
    "floor",
    "Magma can be seen within the cracks in the floor", 
    "crack",
    "Magma can be seen within the cracks in the floor",
    "river",
    "The river flows underneath your feet",
    "lava",
    "The river flows underneath your feet"
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_13.c","northeast",
    "/players/catacomb/Cavern/rooms/lvl2_16.c","south",
  });
}
