
#include "std.h"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object gol;
     if(!present("iron golem")) {
          gol=clone_object("players/bastion/monster/golem");
          move_object(gol, this_object()); }
     return 1;
}

FOUR_EXIT("players/bastion/isle/wiz/spiral3", "north",
     "players/bastion/isle/wiz/drystore", "east",
     "players/bastion/isle/wiz/prisonview", "south",
     "players/bastion/isle/wiz/vault1", "west",
     "Short Hall",
     "You are in a dimly lit corridor, running about twenty feet east to\n"+
     "west. The hall ends at doors at both ends, while a third door leads\n"+
     "south. A stair is through the archway, north.\n",
     1)
