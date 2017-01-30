#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Darker Forest";
long_desc ="  The trail becomes steep and wet underfoot.  It is difficult\n"+
           "to move along the path.  The trail leads west to the safety of\n"+
           "the dim forest and continues upwards to the north.\n";

items = ({
  "trail", "A leafy forest trail, it continues upward to the east\n"+
           "or west to the dim forest",
  "forest","The forest is has many pine and oak trees.  It seems\n"+
           "very old",
  "underfoot","The trail of bark and leaves is slightly damp.\n",
  });

dest_dir = ({
  "/players/softly/winter/rooms/for1.c","west",
  "/players/softly/point/rooms/for4.c","east",
  "/players/softly/winter/rooms/for3.c","north",
  });
}




