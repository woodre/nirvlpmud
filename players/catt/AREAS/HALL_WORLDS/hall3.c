#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

THREE_EXIT(HALL_WORLDS+"hall2","backwards",
           HALL_WORLDS+"hall4","forward",
           WORLD2+"world2","portal",
           "hall of worlds",
  
   "You are on a grey wondering path... you can see no end\n" +
 "in sight... to the side of the path you see hundreds\n" +
"thousands and even millions of little shimmering grey fields\n" +
"into which you think you can enter.\n", 1)


