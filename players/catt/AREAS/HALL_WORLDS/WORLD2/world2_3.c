#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
object slaves;
int i;
i = 0;
  if(!present("slave")) {
   while(i < 5) {
    i += 1;
   slaves = clone_object(NPC+"slave");
  move_object(slaves, this_object());
}
}
}
ONE_EXIT(WORLD2+"world2_2","up",
         "Bottom of the Greytooth Tower",
  "You find yourself in the bottom of the tower and can see the source of\n" +
  "the yells and screams. This room is the holding room for dairines    \n" +
  "slaves. You can tell that many of them have been here for quite some \n" +
  "time.\n", 1)
