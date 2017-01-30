#include "std.h"


/*



*/


FOUR_EXIT("players/rich/quest/hall2.c", "north",
   "players/rich/quest/roomw1.c", "west",
   "players/rich/quest/roome1.c", "east",
   "players/rich/quest/main1.c", "south",
     "hallway",
           "This is a hallway. to the south is a hallway, " +
           "a hallway,  and to the east and west rooms. \n" +
           "to the north a hallway.\n", 1)
realm(){return "NT";}
