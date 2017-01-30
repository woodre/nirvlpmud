#include "room.h"
object rabbit, hat, ax;


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!rabbit || !living(rabbit)) {
     rabbit = clone_object("obj/monster.talk");
     call_other(rabbit, "set_name", "tinman");
     call_other(rabbit, "set_level", 14);
     call_other(rabbit, "set_hp", 210);
     call_other(rabbit, "set_al", 250);
     call_other(rabbit, "set_ac", 11);
     call_other(rabbit, "set_wc", 18);
     call_other(rabbit, "set_short", "The Tinman");
     call_other(rabbit, "set_long", "The Tinman has no heart.\n");
     call_other(rabbit, "load_a_chat", "Tinman says, 'This isn't very nice.'\n)" 
);
     call_other(rabbit, "set_a_chat_chance", 40);
     call_other(rabbit, "load_chat", "Tinman says, 'If I had a heart, I'd be"+
               " as gentle as a lamb.\n");
     call_other(rabbit, "set_chat_chance", 50);
     move_object(rabbit, this_object());
     hat = clone_object("obj/armor");
     call_other(hat, "set_name", "plate");
     call_other(hat, "set_short", "Tin Plate");
     call_other(hat, "set_value", 450);
     call_other(hat, "set_weight", 3);
     call_other(hat, "set_ac", 3);
     call_other(hat, "set_type", "armor");
     move_object(hat, rabbit);

     ax = clone_object("obj/weapon");
     call_other(ax, "set_name", "ax");
     call_other(ax, "set_alias", "axe");
     call_other(ax, "set_short", "Tinman's Ax");
     call_other(ax, "set_class", 11);
     call_other(ax, "set_weight", 2);
     call_other(ax, "set_value", 400);
     move_object(ax ,rabbit);
}
}

TWO_EXIT("players/deathmonger/CASTLE/oz/scarecrow", "north",
         "players/deathmonger/CASTLE/oz/lion", "south",
         "Tinman in forest",
         "You enter a forest, and come upon a rusted tinman.  He looks\n"+
         "agreeable enough, but he doesn't seem to have a heartbeat.\n",
1)
