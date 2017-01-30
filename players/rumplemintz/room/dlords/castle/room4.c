inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("swordmaster"))
    move_object(clone_object(DSWORD),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the fourth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: south and southeast.\n";
  }
}
init() {
  add_action("southeast", "southeast");
  add_action("south", "south");
}
southeast() {
  if(present("dwarf")) {
    write("The Swordmaster bars your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "southeast#players/rumplemintz/room/dlords/castle/room7");
  return 1;
}
south() {
  call_other(this_player(), "move_player", "south#players/rumplemintz/room/dlords/castle/room5");
  return 1;
}
