#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
object lag;
if(!present("lag demon", this_object())) {
   lag = clone_object(NPC+"TEM_lag");
   move_object(lag, this_object());
}
}
TWO_EXIT(TEMPLE+"monkroom1","south",
         TEMPLE+"monkroom3","in",
      "Demon Lord Brakian Temple Path",
        "You are on the path to the monastery. It is an evil place, or\n" +
        "so they say.\n", 1)
