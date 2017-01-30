#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_28","north",
         ORC_VILLAGE+"village_20","east",
         "Orc Village.. village_19",
      "You are on a road in an orc village. The road continues "+
      "to the north and to the east. "+ORC_DESC_SCREAMS+" "+
      ORC_DESC_W_HEDGE+"\n", 1)
