
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object mouse;
     if(!present("mouse")) {
          mouse=clone_object("players/bastion/monster/mouse");
          move_object(mouse, this_object());
          return 1; }
}


TWO_EXIT("players/bastion/isle/wiz/coldstore", "east",
     "players/bastion/isle/wiz/prison_hall", "west",
     "Dry Storage",
     "You enter a room filled with many kegs, crates, casks, and other\n"+
     "containers for storage. Shelves lining the walls are stocked with\n"+
     "various foodstuffs and supplies. A cold mist rises off the metal\n"+
     "door leading east. Another door is west.\n",
     1)
