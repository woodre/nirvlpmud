#include "std.h"


/*



*/


FOUR_EXIT("players/rich/lower/hall3d.c", "north",
   "players/rich/lower/Eroom1d.c", "west",
   "players/rich/lower/mudd2.c", "east",
   "players/rich/lower/hall1d.c", "south",
   "hallway",
           "This is a hallway. to the south is a hallway, " +
           "to the north \n" +
           "a hallway,  and to the east and west rooms. \n",
           1)
realm(){return "enterprise";}
