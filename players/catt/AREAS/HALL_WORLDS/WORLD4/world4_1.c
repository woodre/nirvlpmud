#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset(){
             }
ONE_EXIT("players/wendy/MAZE/maze","south",
         "world 4 maze",
   "You find yourself in a small cave to the north. You are\n"+
   "still in the maze but have entered an underground part of\n"+
   "it. You will want to be very careful down here.\n", 1)
