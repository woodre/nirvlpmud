#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_26","west",
         ORC_VILLAGE+"village_34","north",
         "Orc Village.. village_27",
      "You are on a road that travels north and west in an orc "+
      "village. "+ORC_DESC_SCREAMS+" "+ORC_DESC_E_HEDGE+"\n", 1)
