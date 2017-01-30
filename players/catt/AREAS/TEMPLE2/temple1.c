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
      while(i<10) {
         i += 1;
         missionary = clone_object(NPC+"missionary");
         move_object(missionary, this_object());
      }
   }
   if(!present("hunter")) {
      hunter = clone_object(NPC+"master_hunter");
      move_object(hunter, this_object());
     }
}
THREE_EXIT("room/vill_track","south",
           ZOMBIE_LAND+"zombiland_1","tunnel",
           TEMPLE2+"temple2","north",
           "Demon Temple Path One",
   "You find yourself on the Demon Temple Trail. You are surrounded\n"+
   "by thick undergrowth. Tall shrubs and vines choke the area all \n"+
   "around you. To the north you can barely see a large Keep built \n"+
   "into a small mountain. The dense underbrush obscures most of your\n"+
   "vision, but what you can gives you a feeling of foreboding. To the\n"+
   "south you can see the Town main road. Looking around a little you\n"+
   "notice a small tunnel to the east.\n", 1)
