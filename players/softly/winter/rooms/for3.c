#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Forest Edge";
long_desc ="  The trail is wide with unsure footing.  There is a sudden\n"+
           "chill in the air.  To the north is a bright open area.  To\n"+
           "the south the path narrows entering a darker part of the forest.\n";

items = ({
  "trail", "A slippery forest trail continues upward to the north\n"+
           "or south where it narrows",
  "path", "A slippery forest trail which continues upward to the\n"+
           "north and to the south where it narrows",
  "forest","The forest has many pine and oak trees.  It seems\n"+
           "very old with a few breaks in the trees",
  "underfoot","The trail is slippery and difficult to walk on",
  "air","The air suddenly becomes quite cold",
  "area","The area to the north seems bright and cold",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond1.c","north",
  "/players/softly/winter/rooms/for2.c","south",
  });
}




