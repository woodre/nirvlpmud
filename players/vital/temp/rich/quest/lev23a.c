#include "std.h"


/*



*/


FOUR_EXIT("players/rich/quest/hall3.c", "north",
   "players/rich/quest/lev23b.c", "west",
   "players/rich/quest/lev21c.c", "east",
   "players/rich/quest/main2.c", "south",
     "hallway",
           "This is a hallway. to the south is a hallway, " +
           "a hallway,  and to the east and west rooms. \n" +
           "to the north a hallway.\n", 1)
realm() {return "NT";}
