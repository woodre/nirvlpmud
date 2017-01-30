#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
object missionary;
object hunter;

int i;
i = 0;
   if(!present("missionary")) {
    while(i < 10) {
     i += 1;
   missionary = clone_object(NPC+"TEM_missionary");
   move_object(missionary, this_object());
   }
}
   if(!present("hunter")) {
   hunter = clone_object(NPC+"TEM_master_hunter");
     move_object(hunter, this_object());
                         }
}

THREE_EXIT("room/vill_track","south",
      ZOMBIE_LAND+"zombiland_1","tunnel",
      TEMPLE+"monkroom2","north",
      "Demon Lord Brakian Temple Area Entrance",
    "This is one of the strongholds of the missionaries of the\n" +
    "Demon Lords.\n", 1)


