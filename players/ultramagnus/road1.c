#include "room.h"


#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();



TWO_EXIT("players/ultramagnus/sauroncastle.c", "south",
"players/ultramagnus/nazgul.c", "north",

  "Road1",
"You find yourself on the main road leading north to Gondor\n" +
"In the distance it appears that a great number of companies of orcs \n" +
" and other foul beasts are attacking the city.  \n", 1)
