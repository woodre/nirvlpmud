#include "room.h"
object rabbit, carrot;


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!rabbit || !living(rabbit)) {
     rabbit = clone_object("obj/monster.talk");
     call_other(rabbit, "set_name", "bugs");
     call_other(rabbit, "set_level", 14);
     call_other(rabbit, "set_hp", 210);
     call_other(rabbit, "set_whimpy", 475);
     call_other(rabbit, "set_al", 250);
     call_other(rabbit, "set_ac", 11);
     call_other(rabbit, "set_wc", 18);
     call_other(rabbit, "set_short", "Bugs Bunny");
     call_other(rabbit, "set_long","Bugs is dangerous when he's mad.\n");
     call_other(rabbit, "load_chat","Bugs says: Naaah, what's up Doc?\n");
     call_other(rabbit, "load_chat","Bugs munches on a carrot.\n");
     call_other(rabbit, "load_chat","Bugs says: I'm a Fricasean rabbit!\n");
     call_other(rabbit, "load_chat",
       "Bugs says: If you was any dumber, you'd be Mongo!\n");
     call_other(rabbit, "set_a_chat_chance", 50);
     call_other(rabbit, "load_a_chat","Bugs says: Hey, what's the big idea!?\n");
     call_other(rabbit, "load_a_chat", 
       "Bugs says: You don't want me, I'm all skin and bones!\n");
     rabbit->load_a_chat("Bugs says: Of course you realize, THIS MEANS WAR!\n");
     rabbit->load_a_chat("Bugs says: Why you little...#@&*!\n");
     call_other(rabbit, "set_chat_chance", 50);
     move_object(rabbit, this_object());
     carrot = clone_object("players/deathmonger/MAGIC/carrot");
     move_object(carrot, rabbit);
}
}


ONE_EXIT("players/deathmonger/CASTLE/rabbit_room2","west",
         "Bugs Bunny",
         "Bugs likes to hear himself talk.  See if you can't shut him up.\n",
1)
