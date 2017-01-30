#include "room.h"

object army;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if (!army || (!present("army"))) {
    int i;
    while (i<8) {
      i++;
    army = clone_object("players/hawkeye/room/corporal.c");
      transfer(army, this_object());
    }
  }
}
TWO_EXIT("players/hawkeye/room/newent.c", "west",
       "players/hawkeye/room/newbie3.c", "east",
       "Corporals Room",
       "This is a newbie room where newbies can come\n"+
       "to build up xp and money\n",1)
