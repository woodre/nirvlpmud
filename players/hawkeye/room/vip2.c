#include "room.h"

object army,ob;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/4-star.c");
      transfer(army, this_object());
}
    }
ONE_EXIT("/players/hawkeye/room/rd1.c", "east",
       "VIP TENT",
"You have entered the office of M*A*S*H's first \n" +
"As you enter this tent you are almost blinded by the shining \n" +
"brass. There is an aura of power all about you which makes you \n" +
"want to kill the man before you!.\n",1)
