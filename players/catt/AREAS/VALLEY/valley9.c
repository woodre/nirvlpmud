#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
THREE_EXIT(VALLEY+"valley8","east",
           VALLEY+"valley3","south",
           VALLEY+"valley10","west",
        "valley9",
           "a deserted part of the valley.\n", 1)
