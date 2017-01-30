#include "room.h"

object army,ob,army2;

#undef EXTRA_RESET
#define EXTRA_RESET\
           extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/bj.c");
      transfer(army, this_object());
  if(!army2 || (present("army2"))) {
   army2= clone_object("players/hawkeye/monster/winchester.c");
   transfer(army2, this_object());
}
}
    }
TWO_EXIT("players/hawkeye/room/rd2.c", "west",
     "players/hawkeye/room/off2.c", "south",
     "The 4077th O.R.",
     "Surgical Instruments lay on the tables in very precise rows.\n" +
     "This simple room is used to save the lives of the many shot\n" +
   "up G.I's. You see surgeons working on patients,  I suggest\n" +
  "you don't mess with them while they work.\n", 1) 
