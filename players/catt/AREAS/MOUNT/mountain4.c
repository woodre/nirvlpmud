#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

THREE_EXIT(MOUNT+"mountain3","down",
           MOUNT+"mountain5","up",
           MOUNT+"mountain6","east",
           "a mountain path",
            "You are on the trail on Goblin Mountain leading to the \n" +
            "Goblin strong hold.... a small opening in the dense plant\n" +
            "life seems to form to the east.\n", 1)


