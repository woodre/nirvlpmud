#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
THREE_EXIT(VALLEY+"valley10","east",
           VALLEY+"valley14","south",
           VALLEY+"valley12","west",
        "valley11",
           "a deserted part of the valley.\n", 1)
