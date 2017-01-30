
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

THREE_EXIT("players/bastion/isle/sandy2", "east",
     "players/bastion/isle/grass1", "south",
     "players/bastion/isle/sandybeach", "southwest",
     "Sandy Beach",
     "A grey sea laps the sand. East the wind winds throught the rising\n"+
     "rocks. The shore curves to the southeast, and meets tall grass to the\n"+
     "south.\n",
     1)
