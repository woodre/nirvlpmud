#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_10","west",
         ORC_VILLAGE+"village_3","south",
         ORC_VILLAGE+"village_20","north",
         "Orc Village.. village_11",
      "You are on a north-south road in an orc village. "+
      ORC_DESC_SCREAMS+" "+ORC_DESC_W_HEDGE+" There is some "+
      "kind of room built into the hedge to the west.\n", 1)
