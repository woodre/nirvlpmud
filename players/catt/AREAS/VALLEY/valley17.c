#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

   }

TWO_EXIT(VALLEY+"valley16","east",
         VALLEY+"valley18","west",
         "a worn trail",
         "You are on a well worn trail heading west... to your south\n" +
         "a large mountain rises high into the air. Although it is\n" +
         "a beautiful sight you feel evil stirring in the air.\n", 1)


