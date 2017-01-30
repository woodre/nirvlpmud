#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_4","west",
         ORC_VILLAGE+"village_6","east",
         "Orc Village.. village_5",
      "You are on a road going east-west in an orc village. "+
      ORC_DESC_CRIES+" "+ORC_DESC_S_HEDGE+" \n", 1)
