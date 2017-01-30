#include "room.h"

object army,ob;
object hawkeye;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
/* 03/22/06 Earwax: only one korean per reset, fix */
if (!hawkeye) {
        hawkeye=clone_object("players/pain/NEW/mon/korean.c");
        move_object(hawkeye,this_object());
}
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/blake.c");
      transfer(army, this_object());
}
    }
TWO_EXIT("/players/hawkeye/room/rd1.c", "west",
          "/players/hawkeye/room/off2.c", "east",
       "CO's OFFICE",
"You have entered the office of M*A*S*H's first \n" +
"Commanding officer. He seems to be very fond \n" +
"of his fishing hat, dont't take it from him\n",1)

/* set_no_clean(1); Fred [4.21.06] */
