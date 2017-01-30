#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(ORC_VILLAGE+"village_45","south",
         ORC_VILLAGE+"village_48","north",
         "Orc Village.. village_47",
         "You are in an orc village.\n", 1)
