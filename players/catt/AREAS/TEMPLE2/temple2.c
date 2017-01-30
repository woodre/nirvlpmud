#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
}
TWO_EXIT(TEMPLE2+"temple1","south",
         TEMPLE2+"temple3","northup",
         "Demon Temple Path Two",
   "You are on the Demon Temple Trail. The trail continues to the north\n"+
   "and begins to climb steadily to the temple. The trail also goes to \n"+
   "town, southward. The foliage continues to hamper your efforts to see\n"+
   "the temple clearly.\n", 1)
