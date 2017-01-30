#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
  object zombie;
  int i;
  i = 0;
  if(!present("zombie")) {
    while(i < 5) {
      i += 1;
         zombie = clone_object(NPC+"ZOM_zombie");
         move_object(zombie, this_object());
             }}}
ONE_EXIT(ZOMBIE_LAND+"zombiland_2","south",
      "zombiland_4",
    "The shaft ends here in what seems to be the start of and old\n"+
    "mine of some kind. You can faintly hear the echo of ancient\n"+
    "screams of terror and pain. But you notice, a little nervously\n"+
    "that the sounds are coming from a great distance (like out of\n"+
    "the past) and you don't think that they are immediately \n"+
    "dangerous. But this is still zombie country.\n", 1)
