#include "/players/feldegast/defines.h"

inherit "room/room";

object tree;

init() {
  ::init();
  add_action("cmd_climb","climb");
}
cmd_climb(str) {
  if(str=="tree") {
  if(!tree) {
    tree=clone_object("/players/feldegast/realm/tree");
    tree->set_ground(this_object());
  }
    say(TPN+" climbs up into a tree.\n");
    move_object(TP,tree);
  return 1;
  }
  notify_fail("Climb what?\n");
}
