#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object missionary;

int i;
i = 0;
   if(!present("missionary")) {
    while(i < 5) {
     i += 1;
      missionary = clone_object(NPC+"VAL_missionary");
      move_object(missionary, this_object());
   }
}
}

THREE_EXIT(VALLEY+"valley4","west",
           VALLEY+"valley7","north",
           VALLEY+"valley6","east",
  
           "A small valley",
            "As you near the river your discomfort increases.\n" +
            "it may be that there is an evil presense abroad.\n", 1)


