#include "std.h"


/*



*/


FOUR_EXIT("players/rich/quest/hall2.c", "south",
   "players/rich/quest/hall3.c", "east",
   "players/rich/quest/hall3.c", "west",
   "players/rich/quest/hall3.c", "north",
     "hallway",
           "This is a hallway.To the south a hallway.\n" +
            "To the north is a hallway.\n " ,
               1)
realm(){return "NT";}
