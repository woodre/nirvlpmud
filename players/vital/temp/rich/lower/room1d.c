#include "std.h"


/*



*/


THREE_EXIT("players/rich/lower/hall2d.c", "east",
           "players/rich/lower/guard.c","south",
   "players/rich/lower/turbo1d.c", "west",
   "room",
           "This is a room. to the east is a hallway, " +
           "to the west \n" +
           "a turbolift. \n",
           1)
realm(){return "enterprise";}
