#include "std.h"


/*



*/


TWO_EXIT("players/rich/turbo2.c", "up",

   "players/rich/lower/room2d.c", "east",
     "turbolift" ,
           "This is a turbolift. to the east is a room, " +
           "up to go to main level.\n",
           1)
realm(){return "enterprise";}
