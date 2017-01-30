#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
/*
   object hunter;
   if(!present("hunter")) {
     hunter = clone_object("players/catt/mons/master_hunter");
     move_object(hunter, this_object());
                           }
 /* put hunter in comment becuase of modification of realm */
 /* ->Catt */
}
TWO_EXIT(MOUNT+"level1_3","up",
         MOUNT+"gobpub","down",
         "Stairs cut into the rock",
         "Stairs hewn from the very rock glow a soft green.\n" +
      "This wasn't always an evil place. The stairs continue down.\n", 1)
