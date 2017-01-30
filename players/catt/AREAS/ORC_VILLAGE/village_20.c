#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
FOUR_EXIT(ORC_VILLAGE+"village_19","west",
         ORC_VILLAGE+"village_11","south",
         ORC_VILLAGE+"village_21","east",
         ORC_VILLAGE+"village_29","north",
         "Orc Village.. village_20",
      "You are at an intersection of a small road going east, west "+
      "and south through an orc village. You see a small hut to the "+
      "north. "+ORC_DESC_SCREAMS+"\n", 1)
