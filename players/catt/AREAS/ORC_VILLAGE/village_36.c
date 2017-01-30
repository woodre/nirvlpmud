#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_35","west",
         ORC_VILLAGE+"village_37","east",
         "Orc Village.. village_36",
      ORC_DESC_STAIRCASE+"The staircase continues to the east. "+
      "The path that returns to the village is to the west. "+
      ORC_DESC_SCREAMS+"\n", 1)
