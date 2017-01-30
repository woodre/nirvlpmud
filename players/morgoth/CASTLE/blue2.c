#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset(arg)
{
    if (arg) return;
    return;
}

FOUR_EXIT("players/morgoth/CASTLE/blue1", "west",
           "players/morgoth/CASTLE/blue_pub", "east",
           "players/morgoth/CASTLE/shop", "north",
         "players/morgoth/CASTLE/prize_room", "south",
           "End of Blues Alley",
           "This is the end of Blues Alley\n"+
           "From the east you hear the sounds of a jazz quartet and\n"+
            "the laughter of your fellow adventurers in the Blues Alley Pub.\n"+
            "To the north is a shop.\n\n",1)
