#include "room.h"
object rabbit, money;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
int i;
i = 0;
if (!present("rabbit")) {
while(i<13) {
i += 1;
     rabbit = clone_object("obj/monster");
     call_other(rabbit, "set_name", "rabbit");
     call_other(rabbit, "set_level", 2);
     call_other(rabbit, "set_hp", 30);
     call_other(rabbit, "set_wc", 6);
     call_other(rabbit, "set_ac", 3);
     call_other(rabbit, "set_al", 200);
     call_other(rabbit, "set_short", "A cute little bunny-rabbit");
     call_other(rabbit, "set_long",
              "A snow-white rabbit, with long flowing ears and a pink nose\n");
     move_object(rabbit, this_object());
     money = clone_object("obj/money");
     call_other(money, "set_money", random(80));
     move_object(money, rabbit);
}
}
}

THREE_EXIT("players/deathmonger/east_hall1", "south",
         "players/deathmonger/CASTLE/monty_rabbit", "north",
         "players/deathmonger/CASTLE/rabbit_room2", "east",
         "A room FULL of rabbits.",
         "Welcome to the rabbit room, which, as you can see, is FULL\n"+
         "of these damn rabbits.  Kill them!\n",  1)
