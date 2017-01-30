#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_17","north",
         ORC_VILLAGE+"village_8","west",
         "Orc Village.. village_9",
      "You are on a road going west-north in an orc village. "+
      ORC_DESC_SCREAMS+" "+ORC_DESC_S_HEDGE+" "+ORC_DESC_E_HEDGE+
      "\n", 1)
