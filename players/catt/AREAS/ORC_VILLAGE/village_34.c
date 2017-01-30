#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_27","south",
         ORC_VILLAGE+"village_43","north",
         "Orc Village.. village_34",
      "You are on a north-south road in an orc village. To the "+
      "north stands a vast temple. To the south the village. "+
      ORC_DESC_SCREAMS+" "+ORC_DESC_E_HEDGE+"\n", 1)
