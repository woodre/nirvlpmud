#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

   }

THREE_EXIT(VALLEY+"valley16","west",
           VALLEY+"valley12","north",
           VALLEY+"valley14","east",
          "small valley",
          "you see much of the same but the area seems to clear enough\n" +
        "for you to go both to the west and east, or to continue north\n" +
        "but as you look west their seems to be intense foliage\n" +
        "concentrated in the westerly direction.\n", 1)


