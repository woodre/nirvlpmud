
#include "ansi.h"

inherit "room/room";
reset(arg) {
  object monster;
  if(arg) 
    return ;    
  set_light(0); 
  short_desc = HIK+"Outer Boundary"+NORM; 
  long_desc = "Dead trees line the sides of this massive chasm. Towards the bottom\n"+
           "there appears to be an opening into some old under water cave.\n";
  dest_dir =
  ({ /* needed to signify an array */
  "players/data/OUTERB/ROOMS/room10", "east",
  "players/data/OUTERB/ROOMS/room3", "south"
  });

}
