inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("swashbuckler"))
    move_object(clone_object(DSWASH),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the seventh room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: north and northwest.\n";
  }
}
init() {
  add_action("northwest", "northwest");
  add_action("north", "north");
}
north() {
  if(present("dwarf")) {
    write("The Swashbuckler bars your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "north#players/rumplemintz/room/dlords/castle/room6");
  return 1;
}
northwest() {
  call_other(this_player(), "move_player", "northwest#players/rumplemintz/room/dlords/castle/room4");
  return 1;
}
