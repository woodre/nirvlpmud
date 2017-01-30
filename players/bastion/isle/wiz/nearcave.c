
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object gull;
     if(!present("gull")) {
          gull=clone_object("players/bastion/monster/gull");
          move_object(gull, this_object());
     }
}

THREE_EXIT("players/bastion/isle/wiz/quay", "northeast",
     "players/bastion/isle/wiz/cave1", "east",
     "players/bastion/isle/wiz/shore1", "southeast",
     "Shore",
     "You stand on the western shore of the wizard's isle. A forbidding\n"+
     "cave leads into the earth here. The manor sits atop the island's\n"+
     "central hill, east.\n",
     1)
