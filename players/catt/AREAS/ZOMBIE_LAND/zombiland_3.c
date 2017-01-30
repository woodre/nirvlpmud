#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
   object zombie;
   int i;
   i = 0;
   if(!present("zombie")) {
    while(i < 5) {
      i += 1;
         zombie = clone_object(NPC+"ZOM_zombie");
         move_object(zombie, this_object());
      }}}
ONE_EXIT(ZOMBIE_LAND+"zombiland_1","east",
         "zombiland_3",
      "You notice more open stone coffins and feel the presence of\n"+
      "evil and zombie smell all around you. Good luck zombie hunter.\n", 1)
