#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_short("Before the Mansion");
 set_long(
 "  Tall weeds have overrun what was once a majestic yard.  A stone\n"+
 "footpath is barely visible.  Statues that once lined the path now\n"+
 "lay crumbling in various states of decay.  The footpath ends at a\n"+
 "set of steps, leading up to a large house.  The house stands two\n"+
 "stories high, and the large wooden entrance door is open, hanging\n"+
 "from one hinge.\n");
add_item("blah","blah blah blah");
add_item("blah","blah blah blah");
add_exit(PLAIN+"re3.c","north");
 }
}
init() {
 ::init();
add_action("enter_da_howse","enter");
}
enter_da_howse(str) {
 if(!str || str != "mansion") {FAIL("Are you trying to enter the Mansion?\n"); return 0; }
  write("You climb up the steps and enter the mansion.\n");
  TP->move_player("up the steps and into the mansion#"+PLAIN+"re3b.c");
  return 1;
}
