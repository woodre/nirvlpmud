#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
ONE_EXIT(ORC_VILLAGE+"village_45","east",
         "Orc Village.. village_44",
         "You are in an orc village.\n", 1)
