#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
FOUR_EXIT(ORC_VILLAGE+"village_25","west",
         ORC_VILLAGE+"village_27","east",
         ORC_VILLAGE+"village_17","south",
         ORC_VILLAGE+"village_33","north",
         "Orc Village.. village_26",
      "You are at an intersection of a road that travels east, "+
      "west and south in the orc village. A small hut is to the "+
      "north. "+ORC_DESC_CRIES+"\n", 1)
