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
     call_other(rabbit, "set_hp", 50);
     call_other(rabbit, "set_wc", 2);
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

TWO_EXIT("players/deathmonger/CASTLE/rabbit_room","west",
         "players/deathmonger/CASTLE/bugs","east",
         "A room FULL of rabbits",
         "And if you'd like to see some more of these cute cuddly crea-\n"+
         "tures, here they are!\n",
1)
