#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

   }

THREE_EXIT(VALLEY+"valley2","west",
           VALLEY+"valley9","north",
           VALLEY+"valley4","east",
          "small valley",
          "You see much of the same but the area seems to clear enough\n" +
        "for you to go both to the west and east, or to continue north\n", 1)


