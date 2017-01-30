#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_41","west",
         ORC_VILLAGE+"village_43","east",
         "Orc Village.. village_42",
      ORC_DESC_STAIRCASE+"The staircase continues to the "+
      "west, towards the temple, and ends to the east, "+
      "towards the village. "+ORC_DESC_SCREAMS+"\n", 1)
