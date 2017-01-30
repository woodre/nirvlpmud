
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object mouse;
     if(!present("magic mouse")) {
          mouse=clone_object("players/bastion/monster/mouse");
          move_object(mouse, this_object()); }
     return 1;
}

ONE_EXIT("players/bastion/isle/wiz/kitchen", "west",
     "Pantry",
     "Various foodstuffs and kitchenware line the shelves here. You may\n"+
     "leave west.\n",
     1)
