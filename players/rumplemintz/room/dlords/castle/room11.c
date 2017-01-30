inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("champion"))
    move_object(clone_object(DCHAMP),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the eleventh room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: south and northwest.\n";
  }
}
init() {
  add_action("northwest", "northwest");
  add_action("south", "south");
}
south() {
  if(present("dwarf")) {
    write("The Champion bars your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "south#players/rumplemintz/room/dlords/castle/room12");
  return 1;
}
northwest() {
  call_other(this_player(), "move_player", "northwest#players/rumplemintz/room/dlords/castle/room6");
  return 1;
}
