#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {


}

TWO_EXIT(MOUNT+"mountain7","north",
         MOUNT+"level1_1","south",
  
        "goblin level1",
         "wild cries of goblins and their creatures pierce your ears\n"+
         "as you enter the strong hold you find yourself becoming\n" +
         "chilled... better keep your edge, here is not the place\n" +
                 "to lose it.\n", 1)


