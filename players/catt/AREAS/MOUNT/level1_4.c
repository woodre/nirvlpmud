#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
              }
TWO_EXIT(MOUNT+"level1_3","east",
         MOUNT+"level1_8","north",
        "a small room in strong hold",
   "this is the end of the tunnel.. one small entrance to the\n" +
       "north... you can tell this area doesn't get used much.\n", 1)
