#include "room.h"

object army,ob;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
    army = clone_object("players/blake/monster/hawkeye.c");
      transfer(army, this_object());
}
    }
TWO_EXIT("players/hawkeye/room/rd1.c", "west",
          "players/hawkeye/room/off2.c", "east",
       "CO's OFFICE",
"You have entered the office of M*A*S*H's first \n" +
"Commanding officer. He seems to be very fond \n" +
 "of his fishing hat, don't take it from him\n",1)
