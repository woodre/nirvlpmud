#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
ONE_EXIT(ORC_VILLAGE+"village_14","west",
         "Orc Village.. village_15",
         "You are in and orc village.\n", 1)
