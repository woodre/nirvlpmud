#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

TWO_EXIT(MOUNT+"mountain2","down",
         MOUNT+"mountain4","up",
           "a mountain path",
            "You are on the trail on Goblin Mountain leading to the \n" +
            "Goblin strong hold.\n", 1)

