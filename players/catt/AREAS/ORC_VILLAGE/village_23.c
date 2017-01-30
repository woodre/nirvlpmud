#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
FOUR_EXIT(ORC_VILLAGE+"village_22","west",
         ORC_VILLAGE+"village_31","north",
         ORC_VILLAGE+"village_24","east",
         ORC_VILLAGE+"village_14","south",
         "Orc Village.. village_23",
          "You are at a crossroads in the village. The main pathway seems \n"+
          "to move from east to west now, while there is a slightly smaller \n"+
          "pathway going north. The main road to the entrance of the village \n"+
          "is south. Further to the north you can see a large structure of \n"+
          "some sort. The structures design makes you feel uncomfortable \n"+
          "venturing too near.\n", 1)
