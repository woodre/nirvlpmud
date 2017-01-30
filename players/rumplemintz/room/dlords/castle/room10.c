inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("myrmidon"))
    move_object(clone_object(DMYRM),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the tenth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: north and northeast.\n";
  }
}
init() {
  add_action("northeast", "northeast");
  add_action("north", "north");
}
northeast() {
  if(present("dwarf")) {
    write("The Myrmidon bars your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "northeast#players/rumplemintz/room/dlords/castle/room13");
  return 1;
}
north() {
  call_other(this_player(), "move_player", "north#players/rumplemintz/room/dlords/castle/room9");
  return 1;
}
