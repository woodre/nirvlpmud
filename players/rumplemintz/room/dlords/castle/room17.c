inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("lord"))
    move_object(clone_object(DSUPERLORD),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the seventeenth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: east, northwest and southwest.\n";
  }
}
init() {
  add_action("east", "east");
  add_action("southwest", "southwest");
  add_action("northwest", "northwest");
}

east() {
  if(present("dwarf")) {
    write("The Lord blocks your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "east#/players/rumplemintz/room/dlords/castle/room18");
  return 1;
}
northwest() {
  call_other(this_player(), "move_player", "northwest#players/rumplemintz/room/dlords/castle/room14");
  return 1;
}
southwest() {
  call_other(this_player(), "move_player", "southwest#players/rumplemintz/room/dlords/castle/room16");
  return 1;
}
