#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_20","west",
         ORC_VILLAGE+"village_22","east",
         "Orc Village.. village_21",
      "You are on a small east-west road in the center of an orc "+
      "village. "+ORC_DESC_CRIES+"\n", 1)
