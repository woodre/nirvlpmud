inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("veteran"))
    move_object(clone_object(DVET),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the first room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: north, south, east, and west.\n";
  }
}
init() {
  add_action("east", "east");
  add_action("west", "west");
  add_action("north", "north");
  add_action("south", "south");
}

east() {
  if(present("dwarf")) {
    write("The veteran blocks your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "east#/players/rumplemintz/room/dlords/castle/room8");
  return 1;
}
west() {
  call_other(this_player(), "move_player", "west#players/rumplemintz/room/dlords/castle/ent");
  return 1;
}
south() {
  call_other(this_player(), "move_player", "south#players/rumplemintz/room/dlords/castle/room2");
  return 1;
}
north() {
  call_other(this_player(), "move_player", "north#players/rumplemintz/room/dlords/castle/room5");
  return 1;
}
