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
TWO_EXIT(ZOMBIE_LAND+"zombiland_1","up",
         ZOMBIE_LAND+"zombiland_4","north",
         "zombiland_2",
     "This is the bottom of an old shaft. No one knows why it is\n"+
     "here. But there are zombies around.\n", 1)
