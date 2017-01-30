inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("plaque"))  {
    MOCO("/players/jareel/general_stuff/orlanth_plaque.c"),this_object()); }
  if(!present("initiate"))  {
    MOCO("/players/jareel/monsters/town/orlanthi_infantry.c"),this_object()); }

  if (arg)
    return;

  set_light(1);
short_desc=(BLU+"Orlanth "+NORM+"Temple");

long_desc=
  
  "     The vast entrance of the "+BLU+"Orlanthi"+NORM+" Temple, washes a calmness\n"+
  "washes over your soul as you take a breath.  The open ceiling lets\n"+
  "the cool wind race around the immense marble pillars.  The stone\n"+
  "floor leads deeper into the temple, and the door to the west leads\n"+
  "back out to the road.\n";

  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/entrance/road10","west",
    "/players/jareel/areas/ORLANTHTEMPLE/shrine","east",
  });

}

