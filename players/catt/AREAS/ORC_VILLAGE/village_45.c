#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
FOUR_EXIT(ORC_VILLAGE+"village_44","west",
         ORC_VILLAGE+"village_46","east",
         ORC_VILLAGE+"village_47","north",
         ORC_VILLAGE+"village_39","south",
         "Orc Village.. village_45",
         "You are in an orc village.\n", 1)
