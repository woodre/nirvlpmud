#include "room.h"

object army,ob,ob1;
realm() {return "NT";}
#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
army = clone_object("players/hawkeye/monster/supply1.c");
      transfer(army, this_object());
ob1 = clone_object("players/hawkeye/quest/pipe.c");
move_object(ob1, army);
}
    }
ONE_EXIT("players/hawkeye/room/hq1.c", "west",
     "Supply Room",
 "Do you really want to wait in line?....What should you do?.\n",1)
