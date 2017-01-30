#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_42","west",
         ORC_VILLAGE+"village_34","south",
         "Orc Village.. village_43",
      "You are on a road in an orc village. To the west is a long, "+
      "steep staircase leading to a monstrous temple. To road "+
      "continues to the south towards to the orc village. "+
      ORC_DESC_CRIES+" "+ORC_DESC_N_HEDGE+" "+ORC_DESC_E_HEDGE+
      "\n", 1)
