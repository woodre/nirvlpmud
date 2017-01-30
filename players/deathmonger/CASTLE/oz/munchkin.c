#include "room.h"
object rabbit, money;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
int i;
i = 0;
if (!rabbit || !living(rabbit)) {
while(i<8) {
i += 1;
     rabbit = clone_object("obj/monster");
       call_other(rabbit, "set_name", "munchkin");
     call_other(rabbit, "set_level", 4);
     call_other(rabbit, "set_hp", 60);
     call_other(rabbit, "set_wc", 8);
     call_other(rabbit, "set_wc", 4);
     call_other(rabbit, "set_al", 200);
     call_other(rabbit, "set_short", "A munchkin");
     call_other(rabbit, "set_long", "An innocent little munchkin.\n");
     move_object(rabbit, this_object());
     money = clone_object("obj/money");
     call_other(money, "set_money", random(175));
     move_object(money, rabbit);
}
}
}

TWO_EXIT("players/deathmonger/west_hall2", "north",
         "players/deathmonger/CASTLE/oz/scarecrow","south",
         "Munchkin village",
         "You find yourself in the midst of the munchkin village, knee-\n"+
         "deep in munchkins.  These sweet little creatures throw a party\n"+
         "in your honor and celebrate your coming by dancing in the streets.\n"+
         "The Yellow Brick Road continues to the south.\n",
1)
