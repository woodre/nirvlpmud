#include "//players/feldegast/defines.h"
inherit "/room/room";

object ground_room;
reset(arg) {
  if(arg) return;
  short_desc="A tree";
  long_desc="Gosh...Could it be...A tree?\n";
  set_light(1);
}
init() {
  ::init();
  add_action("cmd_climb","climb");
}
cmd_climb(str) {
  if(str=="down") {
    write("You climb down the tree.\n");
    move_object(TP,ground_room);
    say(TPN+" climbs down from a tree.\n");
  }
  notify_fail("Climb what?\n");
}
set_ground(object ob) {
  ground_room=ob;
}
