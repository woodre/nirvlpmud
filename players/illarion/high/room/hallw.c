inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The entrance hall of the Dojo";
  long_desc=
"You are in a short wood-floored hallway that runs off to the east and opens\n"+
"to the south through a window-flanked doorway.  Although nothing looks new\n"+
"it is obvious that things are well cared for.  Directly opposite the door,\n"+
"you notice a long scrape in the block wall.\n";
  items= ({
    "hallway","That's right, you're standing in it",
    "east","The hallway ends a short distance away",
    "doorway","The doorway appears to open into the dojo itself",
    "window","Old, slightly dirty windows, for an unknown purpose",
    "wall","Ulgy, old, but studry and low maintenance",
    "scrape","Something hard and sharp was dragged along the wall here at\n"+
             "some point",
  });
  dest_dir= ({
    HROOM+"halle","east",
    HROOM+"dojomain","south",
  });
}
