#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object sentry;

int i;
i = 0;
   if(!present("sentry")) {
  while(i < 5) {
    i += 1;
   sentry = clone_object(NPC+"gobsentry");
   move_object(sentry, this_object());
                 }
   }
}

ONE_EXIT(MOUNT+"mountain4","west",
           "ambush on path",
            "YOU HAVE BEEN AMBUSHED... EVEN AS YOU ENTER 10 SENTRIES\n" +
            "JUMP YOU!\n", 1)


