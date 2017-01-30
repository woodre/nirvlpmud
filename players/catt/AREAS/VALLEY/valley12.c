#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
THREE_EXIT(VALLEY+"valley11","east",
           VALLEY+"valley15","south",
           VALLEY+"valley13","west",
        "valley12",
           "a deserted part of the valley.\n", 1)
