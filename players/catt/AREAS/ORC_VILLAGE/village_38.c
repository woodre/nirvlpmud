#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_37","west",
         ORC_VILLAGE+"village_39","east",
         "Orc Village.. village_38",
      ORC_DESC_STAIRCASE+"The staircase continues to the "+
      "east, towards the temple, and to the west, towards "+
      "the village. You notice a large balcony at the top "+
      "staircase. The village is now very far below you to "+
      "the south. "+ORC_DESC_SCREAMS+"\n", 1)
