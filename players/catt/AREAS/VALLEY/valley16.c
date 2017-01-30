#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object goblin;
   int i;
           i = 0;
   if(!present("goblin")) {
  while(i < 2) {
     i +=1;
      goblin = clone_object(NPC+"VAL_goblin");
      move_object(goblin, this_object());
   }
}
}
THREE_EXIT(VALLEY+"valley17","west",
           VALLEY+"valley13","north",
           VALLEY+"valley15","east",
  
           "A small valley",
            "you near the end of the valley and find that you\n" +
            "must continue to the southwest because of the dense\n" +
           "plant life\n", 1)


