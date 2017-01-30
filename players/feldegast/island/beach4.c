#include "/players/feldegast/defines.h"

inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A sandy beach";
  long_desc=
"     You are on a sandy beach.  The cool blue water laps up\n"+
"against the shore.  A rocky crag blocks the beach to the north.\n"+
"You think you see the entrance to a cave a few feet above the\n"+
"the high tide line.\n";
  items=({
    "beach","A broad stretch of sand along this island's shore",
    "water","Clear blue water turning to foam on the rocks",
    "line","The dampness of the sand indicates high tide wasn't long past",
    "crag","A chunk of igneus rock carved out by the water over the\n"+
           "course of years",
    "cave","You can't make out anything inside the cave"
  });
  dest_dir=({
    "/players/feldegast/island/cave","cave",
    "/players/feldegast/island/beach1","south"
  });
}

