#include "room.h"

object army,ob;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
  if(!army || (present("army"))) {
    army = clone_object("players/hawkeye/monster/doctor.c");
      transfer(army, this_object());
}
    }
ONE_EXIT("players/hawkeye/room/j-ent.c", "east",
      "Witch Doctor's Hut",
   "Surounded by little grass huts you begin to get a little nervous.\n" +
    "Looking around you here or see no one except a funny little man who\n"+
      "looks like a witch doctor. They are said to have magical\n"+
   "powers. Do you dare find out?\n",1)
