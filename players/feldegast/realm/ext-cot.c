#include "def.h"
#include "/players/feldegast/defines.h"

short() {
  return "A cottage";
}
long() {
  write(
"This is a small, two story cottage that almost looks like a wooden\n"+
"tower.  The top of it is flat, and you think you see a telescope\n"+
"poking over the edge.  A fireplace runs up the south side of it, and\n"+
"seems to be producing a great deal of heat inside.\n");
}
init() {
  add_action("cmd_enter","enter");
}
cmd_enter(str) {
  if(str=="cottage") {
    write("You open the door and step into the cottage.\n");
    TP->move_player("into the cottage#"+PATH+"cottage1");
    return 1;
  }
  else notify_fail("Enter what?\n");
}
id(str) {
  return str=="cottage";
}
