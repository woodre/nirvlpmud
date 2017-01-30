#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
TWO_EXIT(VALLEY+"valley7","south",
          MALACS_KEEP+"malac1","bridge",
   "malac's entrance",
   "You are at the edge of the river and find that a small\n" +
   "bridge crosses over to a stilted keep in the middle of the\n" +
   "river. A notice marks this as Malac's domain.\n" +
   "He is rumored to be very powerful.\n", 1)
