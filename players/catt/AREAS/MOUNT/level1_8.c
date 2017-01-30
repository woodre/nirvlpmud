#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
object reaver;

   if(!present("reaver")) {
   reaver = clone_object(NPC+"reaver");
     move_object(reaver, this_object());
      }
}
ONE_EXIT(MOUNT+"level1_4","south",
          "reavers room",
          "a dusty store room that has been long forgotten and never used\n", 1)
