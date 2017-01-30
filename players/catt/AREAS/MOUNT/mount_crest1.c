#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
         }
TWO_EXIT(MOUNT+"mountain5","east",
         MOUNT+"mount_crest2","up",
         "mountain_crest1",
    "You notice a small trail heading further up the mountain.\n"+
    "This trail, you suppose, may even go to the very peak of the\n"+
    "mountain. You see a glimmer of snow in the distance.\n", 1)
