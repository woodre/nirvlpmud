#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The stone stairs curve up and out of sight into the darkness above.\n"+
  "The small stone platform, also cut from the solid rock, opens up into\n"+
  "a dark cave to the west.  There seems to be a slight breeze coming\n"+
  "from the cave which keeps the air fresh and cool here.\n";

items = ({
  "stairs","Solid rock and worn slightly in the middle from the many\n"+
           "footsteps that climbed them",
  "darkness","Black, too dark to see a thing",
  "platform","A rough, rectangular opening just tall enough to keep\n"+
             "people from hitting their heads",
});

dest_dir = ({
  "players/eurale/Lab/l2.c","up",
  "players/eurale/Lab/l4.c","west",
});

}

realm() { return "NT"; }
