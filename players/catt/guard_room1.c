#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object demon;

   if(!present("demon")) {
   demon = clone_object(NPC+"guardian");
   move_object(demon, this_object());
   }
}

ONE_EXIT("players/catt/workroom", "up",
         "In guardians quarters",
        "You are in the tower where the mighty catt works his magics.\n", 1)


