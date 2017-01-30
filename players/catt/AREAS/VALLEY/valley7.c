#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
object monk;
int i;
i = 0;
   if(!present("monk")) {
     while( i < 2) {
     i += 1;
      monk = clone_object(NPC+"VAL_monk");
      move_object(monk, this_object());
            }
   }
}
THREE_EXIT(VALLEY+"valley5","south",
           VALLEY+"valley21","north",
           VALLEY+"valley8","west",
          "valley7",
          "River is to the east, this is a small alcove of tree's\n" +
       "and shrubbery. A perfect place for monks to hide out.\n" +
       "A trail leads north.\n", 1)
