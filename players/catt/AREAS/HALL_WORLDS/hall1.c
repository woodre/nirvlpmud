#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

THREE_EXIT(MALACS_KEEP+"malac2","out",
           HALL_WORLDS+"hall2","forward",
         WORLD1+"world1","portal",
           "hall of worlds",
         "This is the hall of worlds. In this hall all the worlds may\n" +
   "be accessed, but you may not want to go to all of them.\n" +
          "be carefull for you never know where you will end up.\n", 1)
  


