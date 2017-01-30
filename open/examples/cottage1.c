#include "def.h"
inherit "room/room";
reset(arg) {
  object elf;
  if(!present("dana")) {
    elf=clone_object("/players/feldegast/mon/dana");
    move_object(elf,this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A cottage";
  long_desc=
"    This cottage is warm and cozy despite the near freezing\n"+
"temperatures outside.  The bottom floor of the cottage is one\n"+
"long room with a kitchen in the northeast corner, a staircase\n"+
"in the corner next to the window, an old bed squeezed between\n"+
"the fireplace and the wall, and a comfy pair of chairs directly\n"+
"in front of the fire.  You immediately feel a sense of warmth\n"+
"and well-being as you step over the threshold.\n";
  items=({
    "fireplace","A stone fireplace with a roaring fire going",
    "bed","A soft narrow bed with a down comforter and feather pillows",
    "kitchen","A few cupboards and a long counter.  Whoever lives here isn't much of a cook",
    "chairs","You can almost imagine two people whiling away a winter night here"
  });
  dest_dir=({
    PATH+"outside","out",
    PATH+"cottage2","up"

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
