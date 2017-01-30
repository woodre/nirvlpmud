#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object missionary;

   if(!present("missionary")) {
      missionary = clone_object(NPC+"VAL_missionary");
      move_object(missionary, this_object());
   }
}

THREE_EXIT(VALLEY+"valley3","west",
           VALLEY+"valley8","north",
           VALLEY+"valley5","east",
  
           "A small valley",
            "You get a bad feeling as you near the river.\n", 1)


