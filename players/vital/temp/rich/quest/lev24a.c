#include "std.h"


/*



*/


FOUR_EXIT("players/rich/quest/main2.c", "north",
   "players/rich/quest/lev23b.c", "west",
   "players/rich/quest/lev24b.c", "east",
   "players/rich/quest/lev22c.c", "south",
     "hallway",
           "This is a hallway. to the south is a hallway, " +
           "a hallway,  and to the east and west rooms. \n" +
           "to the north a hallway.\n", 1)
realm(){return "NT";}
