#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object priest;

int i;
i = 0;
   if(!present("priest")) {
    while(i < 1) {
     i += 1;
   priest = clone_object(NPC+"TEM_demonpriest");
   move_object(priest, this_object());
   }
}
}

TWO_EXIT(TEMPLE+"monkroom2","out",
         TEMPLE+"monkroom4","west",
      "Demon Lord Brakian's Temple",
  
     "You find yourself in the main room of the monastery.\n" +
     "You can see only one other exit besides the door you\n"+
  "came in from. A small priest slips out of the wall\n" +
      "to left and he doesn't look happy to see you.\n", 1)


