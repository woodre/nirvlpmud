#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
THREE_EXIT(VALLEY+"valley9","east",
           VALLEY+"valley2","south",
           VALLEY+"valley11","west",
        "valley10",
           "a deserted part of the valley.\n", 1)
