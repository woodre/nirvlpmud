#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_21","west",
         ORC_VILLAGE+"village_23","east",
         "Orc Village.. village_22",
      "You are on a small east-west road in the center of an orc "+
      "village. "+ORC_DESC_SCREAMS+"\n", 1)