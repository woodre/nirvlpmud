#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
ONE_EXIT(ORC_VILLAGE+"village_1","west",
         "Orc Village... village_2",
         "You are in the guard room at the south entrance into the village.\n"+
         "The room is dank, musty, and stinks of mildew, but is otherwise in\n"+
         "good repair. There is a small table and chairs, and some ratty blankets\n"+
         "in the corner.\n", 1)
