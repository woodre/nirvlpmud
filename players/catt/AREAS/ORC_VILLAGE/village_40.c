#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_39","west",
         ORC_VILLAGE+"village_41","east",
         "Orc Village.. village_40",
      ORC_DESC_STAIRCASE+"The staircase continues to the "+
      "west, towards the temple, and to the east, towards "+
      "the village. You notice a large balcony at the top of "+
      "the staircase. The village is now very far below you to "+
      "the south. "+ORC_DESC_SCREAMS+"\n", 1)
