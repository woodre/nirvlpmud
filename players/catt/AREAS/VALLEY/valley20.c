#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

TWO_EXIT(VALLEY+"valley19","east",
         MOUNT+"mountain1","up",
  
           "a steep trail",
            "You are now on the lost trail into Goblin Mountain...\n" +
            
            "be careful!\n", 1)


