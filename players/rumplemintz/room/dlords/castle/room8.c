inherit "room/room";
#include "ex.h"
reset(arg) {
  if(!present("hero"))
    move_object(clone_object(DHERO),this_object());
  if(!arg) {
  set_light(1);
  short_desc = "1st floor Dwarf castle";
  long_desc = "This is the eigth room of the small, but powerful Dwarven castle.\n"+
  	      "Hope you brought a bunch of healing....\n";
    dest_dir = ({
      "/players/rumplemintz/room/dlords/castle/room1", "west",
    });
  }
}
