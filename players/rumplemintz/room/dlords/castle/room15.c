inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("lord"))
    move_object(clone_object(DLORD),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the fifteenth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: north, south and west.\n";
  }
}
init() {
  add_action("west", "west");
  add_action("north", "north");
  add_action("south", "south");
}

west() {
  call_other(this_player(), "move_player", "west#/players/rumplemintz/room/dlords/castle/room12");
  return 1;
}
south() {
  call_other(this_player(), "move_player", "south#players/rumplemintz/room/dlords/castle/room16");
  return 1;
}
north() {
  call_other(this_player(), "move_player", "north#players/rumplemintz/room/dlords/castle/room14");
  return 1;
}
