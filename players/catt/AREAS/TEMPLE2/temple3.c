#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
   object missionary;
   int i;
   i = 0;
   if(!present("missionary")) {
      while(i<2) {
         missionary = clone_object(NPC+"missionary");
         move_object(missionary, this_object());
         i += 1;
      }
   }
}
TWO_EXIT(TEMPLE2+"temple2","southdown",
         TEMPLE2+"temple4","northup",
         "Demon Temple Path Three",
   "You are on the Demon Temple Trail. The Temple is clearly visible to\n"+
   "the north. You think it would take quite a climb to get to the temple\n"+
   "as the entrance seems to sit at the top of a small mountain. The trail\n"+
   "continues to the south, towards town.\n", 1)
