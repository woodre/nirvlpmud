#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_6","west",
         ORC_VILLAGE+"village_8","east",
         "Orc Village.. village_7",
      "You are on a road going east-west in an orc village. "+
      ORC_DESC_SCREAMS+" "+ORC_DESC_S_HEDGE+"\n", 1)
