#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
ONE_EXIT(MOUNT+"level1_1","west",
          "room",
           "this is a tunnel.\n", 1)
