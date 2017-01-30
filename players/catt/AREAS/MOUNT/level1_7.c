#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
 object gobgirl;
 if(!present("goblin")) {
   gobgirl = clone_object(NPC+"gobgirl");
   move_object(gobgirl, this_object());
    }
}
FOUR_EXIT(MOUNT+"level1_6","north",
          MOUNT+"level1_9","south",
          MOUNT+"gob_res1","west",
          MOUNT+"gob_res2","east",
               "residence cavern",
     "As you enter you notice that you are now in a large cavern inside\n" +
"the mountain. It could be pleasant but for the obnoxious sounds \n" +
"and smells. You see what must be goblin homes carved into the \n" +
        "sides of the cavern.\n", 1)
