inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if(!present("smith")){
    if(!present("smith"))  {MOCO("/players/jareel/monsters/chaos/woods2/smith.c"),this_object());}
	
  if (arg)
    return;

  set_light(1);
  short_desc=(HIK+"The Master Blacksmith shop"+NORM);
  long_desc=
    "A deep red glow, burning with intense heat, burns red hot from\n"+
    "the blacksmith's forge.  Unfinished armor and weapons line the\n"+
    "walls of the shop.  The anvil, pounded and beaten, rests in the\n"+
    "center of the room.  The shop is very clean and organised for a\n"+
    "man of this craft\n";

  items = ({ ITEMS });

  dest_dir = ({
  "/players/jareel/areas/entrance/road10","south",
  });

}

}