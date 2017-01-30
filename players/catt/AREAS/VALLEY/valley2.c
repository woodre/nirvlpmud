#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

   }

FOUR_EXIT(VALLEY+"valley1","south",
          VALLEY+"valley14","west",
          VALLEY+"valley10","north",
          VALLEY+"valley3","east",
          "small valley",
   "You see much of the same but the area seems to clear enough\n" +
   "so that you can see an entire little valley to your north and\n" +
   "a vast unknown mountain to the southwest. A large outcrop stands\n" +
  "to the northwest.\n", 1)

