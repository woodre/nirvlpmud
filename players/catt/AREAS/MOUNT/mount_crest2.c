#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
              }
TWO_EXIT(MOUNT+"mount_crest1","down",
         MOUNT+"mount_crest3","up",
         "mount_crest2",
    "You climb up the trail for what seems hours, but you seem\n"+
    "to be making some kind of progress. You now see small patches\n"+
    "of snow along the trail, and large patches up just a little\n"+
    "farther.\n", 1)
