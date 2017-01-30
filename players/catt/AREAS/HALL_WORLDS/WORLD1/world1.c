#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
TWO_EXIT(HALL_WORLDS+"hall1","out",
         WORLD1+"world1_b","north",
         "world1 of hall",
   "You find yourself in a strange palace of sorts. You \n" +
   "entered this world from a strange looking portal fixed\n" +
           "to a rock in the center of some imperial gardens.\n" +
  "As you look at around you notice that the gardens have\n" +
         "been left alone for quite sometime. Most everything but the\n" +
  "trees are dead.\n", 1)
