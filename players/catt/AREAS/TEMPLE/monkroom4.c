#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
  object slayer;
  int i;
  i = 0;
  if(!present("slayer")) {
    while(i < 2) {
      i += 1;
   slayer = clone_object(NPC+"TEM_slayer");
   move_object(slayer, this_object());
                 }
                               }
             }
THREE_EXIT(TEMPLE+"monkroom3","east",
           TEMPLE+"monkroom6","north",
           TEMPLE+"monkroom5","down",
      "Demon Lord Brakian's Temple Alcove",
         "As you enter this little alcove you are made very aware that\n"+
         "this monastery is used for more than its intended purpose. A \n"+
         "well used stairwell is down an open trap door. Another opening\n"+
         "is to the north. The alcove is dimly lit.\n", 1)
