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
                    } } }
THREE_EXIT(TEMPLE+"monkroom1","out",
           ZOMBIE_LAND+"zombiland_2","down",
           ZOMBIE_LAND+"zombiland_3","west",
           "zombiland_1",

     "You find yourself in an underground cemetary. The place is\n"+
     "very old and musty and you can see holes and splits in the\n"+
     "massive stone coffins. The whole area is seething with an\n"+
     "evil presence. You had best be careful, this area is famed\n"+
     "for zombies and only seasoned zombie hunters have it easy.\n", 1)
