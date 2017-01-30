inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("swashbuckler"))
    move_object(clone_object(DSWASH),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the ninth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: south and southwest.\n";
  }
}
init() {
  add_action("southwest", "southwest");
  add_action("south", "south");
}
south() {
  if(present("dwarf")) {
    write("The Swashbuckler bars your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "south#players/rumplemintz/room/dlords/castle/room10");
  return 1;
}
southwest() {
  call_other(this_player(), "move_player", "southwest#players/rumplemintz/room/dlords/castle/room3");
  return 1;
}
