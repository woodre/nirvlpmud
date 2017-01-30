#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
   object sentry;
   int i;
   i = 0;
   if(!present("sentry")) {
      while(i < 2) {
         i += 1;
      sentry = clone_object(NPC + "gobsentry");
         move_object(sentry, this_object());
                   }
               }
   }
THREE_EXIT(MOUNT+"level1_2","east",
           MOUNT+"level1_4","west",
           MOUNT+"level1_stairs_down","down",
          "goblin mountain... level1_3",
          "a set of stairs has been cut into the tunnel here leading down\n" +
          "you can hear muffled yells and curses coming from below.\n", 1)
