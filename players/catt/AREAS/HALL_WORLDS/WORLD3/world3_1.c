#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

   }

TWO_EXIT(HALL_WORLDS+"hall4","tree",
         WORLD3+"world3_pub","enter",
       "world 3 of hall of worlds (callahans)",

"The portal exits from a large tree that is on the curb to\n" +
"a rather small and dimly lit parking lot. A small neon sign\n" +
"proclaims the place as callahan's saloon. It is rumored that\n" +
"only the troubled people of the galaxy can get here, you got \n" +
"problem this is the place to drink it out. (remember that tree)\n", 1)

