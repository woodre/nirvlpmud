#include "room.h"

object doggp;
object hawkeye;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
        hawkeye=clone_object("players/pain/NEW/mon/korean.c");
        move_object(hawkeye,this_object());
  if (!doggp || (!present("armys"))) {
    int i;
    while (i<8) {
      i++;
    doggp = clone_object("players/hawkeye/monster/sarge.c");
      transfer(doggp, this_object());
    }
  }
}
TWO_EXIT("players/hawkeye/room/newbie6.c", "up",
       "players/hawkeye/room/newbie8.c", "east",
       "Sargeants Room",
       "This is a newbie room where newbies can come\n"+
       "to build up xp and money\n",1)
