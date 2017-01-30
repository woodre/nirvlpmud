#include "room.h"
object rabbit, hat;


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!rabbit || !living(rabbit)) {
     rabbit = clone_object("obj/monster.talk");
     call_other(rabbit, "set_name", "lion");
     call_other(rabbit, "set_level", 14);
     call_other(rabbit, "set_hp", 210);
     call_other(rabbit, "set_whimpy", 190);
     call_other(rabbit, "set_al", 250);
     call_other(rabbit, "set_ac", 11);
     call_other(rabbit, "set_wc", 18);
     call_other(rabbit, "set_short", "The Cowardly Lion");
    call_other(rabbit, "set_long", "A COWARD, isn't he?\n");
     call_other(rabbit, "load_a_chat", "Lion says, 'I'm such a pansy!'");
     call_other(rabbit, "set_a_chat_chance", 50);
     call_other(rabbit, "load_chat", "Lion says, 'I'm a born coward.'");
     call_other(rabbit, "seT_chat_chance", 50);
     move_object(rabbit, this_object());
     hat = clone_object("obj/armor");
     call_other(hat, "set_name", "courage");
     call_other(hat, "set_short", "Courage");
     call_other(hat, "set_long", "The Red Badge of Courage.\n");
     call_other(hat, "set_value", 850);
     call_other(hat, "set_weight", 1);
     call_other(hat, "set_ac", 1);
     call_other(hat, "set_type", "amulet");
     move_object(hat, rabbit);
}
}


TWO_EXIT("players/deathmonger/CASTLE/oz/tinman", "north",
         "players/deathmonger/poppies", "south",
         "Cowardly Lion",
         "The forest darkens.  You can hear creepy-crawly creatures in\n"+
         "the bushes.  Your sense of fear and trepidation heightens.  The\n"+
         "tension is unbearable.  Then, like a flash of lightning, a lion\n"+
         "leaps from the bushes straight at you!\n",
1)
