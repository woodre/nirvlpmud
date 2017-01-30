
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

TWO_EXIT("players/bastion/isle/wiz/shore2", "east",
     "players/bastion/isle/wiz/nearcave", "northwest",
     "Shore",
     "The shore continues around the island here, turning northwest.\n"+
     "A breeze rustles through your hair as you catch the occasional\n"+
     "cry of gulls. The manor looms above you, northeast.\n",
     1)
