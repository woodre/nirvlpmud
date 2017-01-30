#include "room.h"

object doggp;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if (!doggp || (!present("armys"))) {
    int i;
    while (i<8) {
      i++;
    doggp = clone_object("players/hawkeye/monster/sarge.c");
      transfer(doggp, this_object());
    }
  }
}
/* Eastern portion removed as it is just sergeants and no description
TWO_EXIT("players/hawkeye/room/newbie2.c", "west",
       "players/hawkeye/room/newbie4.c", "east",
*/
ONE_EXIT("players/hawkeye/room/newbie2.c","west",
       "Sergeants Room",
       "This is a newbie room where newbies can come\n"+
       "to build up xp and money\n",1)
