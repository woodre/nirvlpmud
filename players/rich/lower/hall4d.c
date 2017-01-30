#include "std.h"


/*



*/


FOUR_EXIT("players/rich/lower/hall5d.c", "north",
   "players/rich/lower/troi.c", "west",
   "players/rich/lower/borg.c", "east",
   "players/rich/lower/hall3d.c", "south",
   "hallway",
           "This is a hallway. to the south is a hallway, " +
           "to the north \n" +
           "a hallway,  and to the east and west rooms. \n",
           1)
realm(){return "enterprise";}
