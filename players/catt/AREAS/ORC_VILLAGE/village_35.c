#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_28","south",
         ORC_VILLAGE+"village_36","east",
         "Orc Village.. village_35",
      "You are on a road in an orc village. To the east is a "+
      "long steep staircase leading to a monstrous temple. The "+
      "road continues to the south towards the orc village. "+
      ORC_DESC_CRIES+" "+ORC_DESC_N_HEDGE+" "+ORC_DESC_E_HEDGE+
      "\n", 1)
