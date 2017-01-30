#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object commander;
object emperor;

int i;
i = 0;
   if(!present("commander")) {
    while(i < 1) {
     i += 1;
   commander = clone_object(NPC+"lionmancom");
  move_object(commander, this_object());
   }
}
if(!present("emperor")) {
   emperor = clone_object(NPC+"emperor");
   move_object(emperor, this_object());
      }
}

ONE_EXIT(WORLD1+"world1_b","down",
   "world1.. imperial palace",
  
  "This is the emperor's hiding room... he doesn't want to see\n" +
         "anyone... especially when they are all trying to kill him..\n " +
  "the only one who stands with him are his Lion Man\n" +
    "Guard Commander and his guards.\n", 1)


