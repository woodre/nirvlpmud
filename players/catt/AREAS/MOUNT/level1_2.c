#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
              }
TWO_EXIT(MOUNT+"level1_1","east",
         MOUNT+"level1_3","west",
         "goblin mountain... level1_2",
         "you feel better going in this direction for some reason... \n" +
         "the cavern has narrowed into a tight tunnel that only a few \n" +
         "walk abreast.\n", 1)
