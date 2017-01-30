#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
FOUR_EXIT(ORC_VILLAGE+"village_1","south",
         ORC_VILLAGE+"village_5","west",
         ORC_VILLAGE+"village_7","east",
         ORC_VILLAGE+"village_14","north",
         "Orc Village.. village_6",
          "You find yourself at a crossroads in the village. A rough \n"+
          "road, more of well beaten dirt path, runs to the east and \n"+
          "west. The main road into the village runs to the north and \n"+
          "the exit out the village is to the south. You hear loud screams\n"+
          " and yells all around you.\n", 1)
