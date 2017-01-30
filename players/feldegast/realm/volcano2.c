#include "/players/feldegast/defines.h"
#include "def.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  short_desc="Mountain Ledge";
  long_desc=
"  This narrow ledge is perhaps twenty or thirty meters from the top\n\
of the mountain.  A narrow opening in the rock leads into a cave.\n\
From this ledge, you can see all across Chalynsta.\n";
  items=({
    "opening","It is too dark to see very far into the cave",
  });
  dest_dir=({
    PATH+"volcano1","descend",
  });
}
void init() {
  ::init();
  add_action("cmd_enter","enter");
  add_action("cmd_climb","climb");
}
int cmd_enter(string str) {
  if(!str || str!="opening") {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You carefully enter the narrow opening.\n");
  say(TPN+" carefully enters the narrow opening.\n");
  move_object(TP,PATH+"volc_cave");
  return 1;
}
int cmd_climb(string str) {
  if(!present("climbing_gear",TP)) {
    write("You don't have the proper equipment to make such an assent.\n");
    return 1;
  }
  write("Using your climbing gear, you ascend to the top of the mountain.\n");
  say(TPN+" uses "+TP->query_possessive()+" climb gear to ascend to the top of the mountain.\n");
  move_object(TP,PATH+"caldera");
  return 1;
}
