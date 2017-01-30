
#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
     add_action("step", "step");
}

#undef EXTRA_RESET 
#define EXTRA_RESET extra_reset();

extra_reset(){
}

TWO_EXIT("players/bastion/isle/wiz/cave2", "up",
       "players/bastion/room/limbo", "step",
       "Transport",
       "A long winding tunnel leads to a small cave. The walls of the\n"+
       "cave drip with moisture, collecting here and there into small\n"+
       "puddles.  Aside from a small, silver disc near the southern wall\n"+
       "there is nothing of interest here.\n",
       1)

step() {
     write("You enter the drifting plane of limbo...\n");
     return 0;
}
