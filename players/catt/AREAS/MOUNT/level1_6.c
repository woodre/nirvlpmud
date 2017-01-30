#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
TWO_EXIT(MOUNT+"level1_5","north",
         MOUNT+"level1_7","south",
         "goblin residence entrance",
      "This is the entrance to the goblin residence district. No doubt\n" +
      "you will find some rather interesting types of gobins here. You\n" +
      "also notice that the tunnel here seems to open up into a rather \n" +
      "large cavern of some kind. Maybe you should venture forth to explore\n" +
      "some more for yourself.\n", 1)

