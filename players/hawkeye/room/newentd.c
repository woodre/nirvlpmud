#include "room.h"

object gar;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if (!gar || (!present("private"))) {
    int i;
    while (i<15) {
      i++;
    gar = clone_object("players/hawkeye/monster/private.c");
      transfer(gar, this_object());
    }
  }
}
ONE_EXIT("players/hawkeye/room/newent.c", "up",
       "Privates Room",
       "This is a newbie room where newbies can come\n"+
       "to build up xp and money\n",1)
