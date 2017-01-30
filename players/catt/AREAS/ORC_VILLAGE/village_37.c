#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_36","west",
         ORC_VILLAGE+"village_38","east",
         "Orc Village.. village_37",
      ORC_DESC_STAIRCASE+"The staircase continues to the "+
      "east, towards the temple, and to the west, towards "+
      "the village. You notice that the village is below you "+
      "to the south. "+ORC_DESC_CRIES+"\n", 1)
