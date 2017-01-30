#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
}
TWO_EXIT(HALL_WORLDS+"hall3","portal",
         WORLD2+"world2_2","down",
         "The Greytooth Tower",
     "This is denindruik, The great tower of druinean. Called greytooth\n" +
     "in the common tongue, it is a tall tower built of powerfull stone\n" +
     "and mighty dwarven skill. It is now controlled by the evil sorceress\n" +
   "Dairine the Dark Hearted. You are currently in the top most\n" +
   "room of the tower.\n", 1)
