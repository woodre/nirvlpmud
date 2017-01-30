#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
              }
THREE_EXIT(MOUNT+"mountain10","north",
           MOUNT+"level1_2","west",
           MOUNT+"level1_5","east",
           "goblin mountain... level1",
           "you find that you can't go any further south but must decide\n" +
           "if you want to go east or west... more noise is to the east.\n", 1)
