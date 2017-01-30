#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Dimly Lit Forest";
long_desc ="  The trail becomes steeper and softer underfoot.  It is\n"+
           "difficult to see the westward forest. The trail leads west\n"+
           "to the dim forest and continues upwards to the east.\n";

items = ({
  "trail", "A leafy forest trail, it continues upward to the east\n"+
           "or west to the dim forest",
  "forest","The forest is has many pine and oak trees.  It seems\n"+
           "very old",
  "underfoot","The trail of bark and leaves is slightly damp",
  });

dest_dir = ({
  "/room/south/sforst2.c","west",
  "/players/softly/winter/rooms/for2.c","east",
  });
}




