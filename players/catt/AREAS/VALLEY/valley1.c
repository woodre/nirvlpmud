#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

   }

TWO_EXIT("room/plane9","leave",
         VALLEY+"valley2","north",
         "A small valley",
              "You enter a small valley area with a river to the east and\n" +
      "a very large mountain to the southwest. A large outcrop is\n" +
         "to the north west.\n", 1)


