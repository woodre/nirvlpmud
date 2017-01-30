#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_11","north",
         ORC_VILLAGE+"village_4","east",
         "Orc Village.. village_3",
      "You find yourself in the southwest corner for the "+
      "orc village. The road continues to the north and "+
      "the east. "+ORC_DESC_CRIES+" A thick hedge with thorns "+
      "as thick and sharp as spikes runs to the south and west "+
      "of you. \n", 1)
