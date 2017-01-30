#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object goblin;

int i;
i = 0;
   if(!present("goblin")) {
    while(i < 5) {
        i += 1;
      goblin = clone_object(NPC+"VAL_gobmove");
      move_object(goblin, this_object());
                 }
   }
}

TWO_EXIT(VALLEY+"valley18","east",
         VALLEY+"valley20","west",
  
           "A worn trail",
            "This is part of the goblin trail of sorrows.. follow it\n" +
            "carefully.\n", 1)


