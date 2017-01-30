#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("board", "board");
}

FOUR_EXIT("players/bastion/isle/wiz/entrance", "north",
	  "players/bastion/isle/wiz/shore3", "east",
	  "players/bastion/isle/wiz/shore1", "west",
	  "players/bastion/isle/inlet", "board",
	  "Shore",
	  "A boat stands here on the shore. Above you is a small castle\n"+
	  "with a single tower. The remains of a path lead up the hill. The\n"+
	  "shore continues east and west.\n",
	  1)

board() {
     write("You board the boat and travel across the sea...\n");
     return 0;
}
