#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object lionman;

int i;
i = 0;
  if(!present("lionman")) {
   while( i < 2) {
     i += 1;
   lionman = clone_object(NPC+"lionman");
   move_object(lionman, this_object());
   }
}
}

TWO_EXIT(WORLD1+"world1","south",
         WORLD1+"world1_c","up",
  
    "world1.. imperial palace",
  "You have now re-entered the palace. Two guards stand here \n" +
   "protecting the crazy emperor from assassins. His personal\n" +
   "chambers are up the steps.\n", 1)


