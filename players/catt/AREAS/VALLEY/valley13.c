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

TWO_EXIT(VALLEY+"valley12","east",
         VALLEY+"valley16","south",
  
                "valley13",
                  "you see a small band of missionaries heading for\n" +
           "a meeting somewhere.\n", 1)


