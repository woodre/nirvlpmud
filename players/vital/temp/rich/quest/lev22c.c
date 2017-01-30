#include "std.h"


/*



*/


FOUR_EXIT("players/rich/quest/lev24b.c", "north",
   "players/rich/quest/lev21d.c", "west",
   "players/rich/armor.c", "east",
   "players/rich/quest/lev21b.c", "south",
     "hallway",
           "This is a hallway. to the south is a hallway, " +
           "a hallway,  and to the east and west rooms. \n" +
           "to the north a hallway.\n", 1)
realm(){return "NT";}
