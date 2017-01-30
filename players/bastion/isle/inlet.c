
#include "std.h"


#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("board", "board");
}

TWO_EXIT("players/bastion/isle/sandy2", "west",
     "players/bastion/isle/wiz/shore2", "board",
     "Rocky Inlet",
     "You have come upon a small inlet sheltered by rock. The tremulous\n"+
     "waters collapse into shallow ripples before reaching shore. Moored\n"+
     "near the beach is a weathered sailing craft. Its single mast remains\n"+
     "intact, the canvas still furled in the rigging. It appears you could\n"+
     "board her.\n",
     1)

board() {
     write("You board the boat and travel across the sea...\n");
     return 0;
}
