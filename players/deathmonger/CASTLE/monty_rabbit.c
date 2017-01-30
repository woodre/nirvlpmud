#include "room.h"
object rabbit, money;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!present("rabbit")) {
     rabbit = clone_object("players/deathmonger/MONSTERS/rabbit");
     move_object(rabbit, this_object());
     money = clone_object("obj/money");
      call_other(money, "set_money", random(600));
     move_object(money, rabbit);
}
}

ONE_EXIT("players/deathmonger/CASTLE/rabbit_room", "south",
         "You come to a dark cave.",
         "There's a dark cave, and a single rabbit in front of it, nibbling\n"+
         "on some clover.  A very peaceful scene.\n",
1)
