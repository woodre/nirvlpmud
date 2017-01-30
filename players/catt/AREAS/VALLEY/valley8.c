#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
THREE_EXIT(VALLEY+"valley7","east",
           VALLEY+"valley4","south",
           VALLEY+"valley9","west",
           "valley8",
           "a deserted part of the valley.\n", 1)
