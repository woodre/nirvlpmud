#include "room.h"
object rabbit, hat;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!rabbit || !living(rabbit)) {
     rabbit = clone_object("obj/monster.talk");
     call_other(rabbit, "set_name", "scarecrow");
     call_other(rabbit, "set_level", 12);
     call_other(rabbit, "set_hp", 180);
     call_other(rabbit, "set_al", 250);
     call_other(rabbit, "set_ac", 9);
     call_other(rabbit, "set_wc", 16);
     call_other(rabbit, "set_short", "The Scarecrow");
     call_other(rabbit, "set_long", "The Scarecrow is melancholy because\n"+
               "he doesn't have a brain.  Can you help him?  I think not.\n");
     call_other(rabbit, "load_a_chat", "NO FIREBALLS!!!");
     call_other(rabbit, "load_a_chat", "Are you picking on me just because"+
     "I'm retarded?");
     call_other(rabbit, "set_a_chat_chance", 3);
     call_other(rabbit, "load_chat", "Scarecrow says, if I only had a brain!"); 
     call_other(rabbit, "load_chat", "You know, I'm probably smarter than"+
              " you...");
     call_other(rabbit, "set_chat_chance", 2);

     move_object(rabbit, this_object());
     hat = clone_object("obj/armor");
     call_other(hat, "set_name", "hat");
     call_other(hat, "set_short", "Scarecrow's Hat");
     call_other(hat, "set_long", "The hat of the Scarecrow.\n");
     call_other(hat, "set_value", 600);
     call_other(hat, "set_ac", 1);
     call_other(hat, "set_type", "helmet");
     move_object(hat, rabbit);
}
}

TWO_EXIT("players/deathmonger/CASTLE/oz/munchkin", "north",
         "players/deathmonger/CASTLE/oz/tinman", "south",
         "Scarecrow on post",
         "At this crossroads, there's a Scarecrow on a post mumbling to him-\n"+
         "self.  He is very depressed, and stupid, but probably smarter\n"+
         "than you.  He's really a very nice scarecrow.\n",  1)
