#include "std.h"


/*



*/


THREE_EXIT("players/rich/hall2.c", "east",
   "players/rich/turbo1.c", "west",
   "players/rich/shop.c", "north",
   "room",
           "This is a corridor. " +
           "To the north the Quartermaster`s store.\n",
           1)
realm(){return "enterprise";}
