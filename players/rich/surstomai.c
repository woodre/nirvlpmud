#include "std.h"


/*



*/


THREE_EXIT("players/rich/shop.c", "east",
   "players/rich/surshpweas.c", "west",
   "players/rich/surshparms.c", "north",
   "room",
           "This is the main room of the starfleet surplus store.\n" +
           "To buy weapons go west,to buy anything else go north.\n" +
           "To the east is the quartermaster`s store.\n",
           1)
realm(){return "enterprise";}
