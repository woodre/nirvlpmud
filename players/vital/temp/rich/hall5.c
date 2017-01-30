#include "std.h"


/*



*/


FOUR_EXIT("players/rich/forward.c", "north",
   "players/rich/room2.c", "west",
   "players/rich/Eq.c", "east",
   "players/rich/hall4.c", "south",
     "hallway",
           "This is a corridor.\n" +
           "To the north is 10 forward.\n", 1)
realm(){return "enterprise";}
