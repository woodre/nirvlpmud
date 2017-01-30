
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

TWO_EXIT("players/bastion/isle/wiz/shore3", "southwest",
     "players/bastion/isle/wiz/shore5", "northwest",
     "Shore",
     "You are on the eastern side of the island. The indigenous flora,\n"+
     "mostly grasses and weed-like flowers, is in greater abundance\n"+
     "here. The shore continues northwest and southwest.\n",
     1)
