#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object sentry;

int i;
i = 0;
   if(!present("sentry")) {
     while(i < 2) {
        i += 1;
   sentry = clone_object(NPC+"gobsentry");
   move_object(sentry, this_object());
                 }
   }
}

TWO_EXIT(VALLEY+"valley20","down",
         MOUNT+"mountain2","up",
  
           "a mountain path",
            "You are at the gateway to Goblin Mountain.. It doesn't look\n" +
            "like much, in fact there isn't even a proper gate anymore, \n" +
          "but the way is treacherous and you may find yourself 6ft under.\n" +
            "if you are not careful.\n", 1)


