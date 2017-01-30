inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("superhero"))
    move_object(clone_object(DSUPER),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the twelvth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n"+
	      "Obvious exits: north, south and east.\n";
  }
}
init() {
  add_action("east", "east");
  add_action("north", "north");
  add_action("south", "south");
}

east() {
  if(present("dwarf")) {
    write("The Superhero blocks your way.\n");
    return 1;
  }
  call_other(this_player(), "move_player", "east#/players/rumplemintz/room/dlords/castle/room15");
  return 1;
}
south() {
  call_other(this_player(), "move_player", "south#players/rumplemintz/room/dlords/castle/room13");
  return 1;
}
north() {
  call_other(this_player(), "move_player", "north#players/rumplemintz/room/dlords/castle/room11");
  return 1;
}
