#include "def.h"
inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A clearing";
  long_desc=
"    This is a large, oval-shaped clearing surrounded by pine\n"+
"and spruce trees.  On the southern edge of the clearing is\n"+
"a brilliant azure portal with no apparent means of support.\n"+
"To the north, a huge snow-capped mountain dominates the\n"+
"horizon.  The only path leading from this clearing is in that\n"+
"direction.\n";
  items=({
    "portal","It shimmers through several shades of blue",
    "ship","A sleak, fast vessel bristling with cannons.  Perfect for piracy",
    "beach","A broad stretch of sand along the shore of this island",
    "water","Cool blue water with bits of seaweed and plankton in it",
    "shore","The shore stretches north and south from here"
  });
  dest_dir=({
    PATH+"trail1","north",
    "/players/feldegast/shrine","portal"

  });
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
