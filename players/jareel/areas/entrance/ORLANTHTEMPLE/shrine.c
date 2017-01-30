inherit "room/room";

#include "defs.h"

void reset(int arg) {

  if (arg)
    return;

  set_light(1);
  short_desc=(BLU+"Orlanth "+NORM+"Temple");

  long_desc=
    "     This appears to be the main shrine of the Orlanthi temple.  The\n"+
    "crystal blue sky embraces the room with a whipping whistling wind.  A \n"+
    "small ornate shrine rests in the centre of this auditorium, surrounded\n"+
    "by several wooden benches.  Doors rest on the south, west and east walls.\n";

  items = ({ ITEMS });

  dest_dir = ({
    "/players/jareel/areas/entrance/ORLANTHTEMPLE/foyer","west",
    "/players/jareel/areas/entrance/ORLANTHTEMPLE/runelord","east",
    "/players/jareel/areas/entrance/ORLANTHTEMPLE/initiate","south",
  });

}

