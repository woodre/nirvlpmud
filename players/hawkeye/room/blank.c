#include "room.h"

object army,ob;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/x.c");
      transfer(army, this_object());
}
    }
ONE_EXIT("players/hawkeye/room/rd3.c", "west",
       "M*A*S*H Swamp",
     "the beds but they appear to be locked. The man who\n"+
