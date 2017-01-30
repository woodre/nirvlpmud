#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
THREE_EXIT(ORC_VILLAGE+"village_9","south",
         ORC_VILLAGE+"village_18","east",
         ORC_VILLAGE+"village_26","north",
         "Orc Village.. village_17",
      "You are on a road going north-south in an orc village. "+
      ORC_DESC_CRIES+" "+ORC_DESC_E_HEDGE+" There is some kind "+
      "of room built into the hedge to the east. \n", 1)
