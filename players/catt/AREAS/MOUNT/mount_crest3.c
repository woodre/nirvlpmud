#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
              }
TWO_EXIT(MOUNT+"mount_crest2","down",
         MOUNT+"mount_peak","up",
         "mount_crest3",
    "After climbing forever you finally see the peak and are\n"+
    "within an hours worth of climbing. You may wish to be careful\n"+
    "because the way looks treacherous.\n", 1)
