#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object dorothy, toto, basket;
extra_reset() {
     if(!dorothy ||!living(dorothy)) {
     dorothy = clone_object("obj/monster");
     call_other(dorothy, "set_name", "dorothy");
     call_other(dorothy, "set_level", 6);
     call_other(dorothy, "set_wc", 10);
     call_other(dorothy, "set_ac", 5);
     call_other(dorothy, "set_chat_chance", 50);
      call_other(dorothy, "load_chat","Dorothy sings:  Somewhere, over the"+
               " rainbow...\n");
     call_other(dorothy, "set_a_chat_chance", 50);
     call_other(dorothy, "load_a_chat", "I don't think we'll ever get back"+
               " to Kansas now, Toto...\n");
     call_other(dorothy, "set_hp", 100);
     move_object(dorothy, this_object());

     if(!toto ||!living(toto)) {
      toto = clone_object("obj/monster");
      call_other(toto, "set_name", "toto");
      call_other(toto, "set_level", 3);
      call_other(toto, "set_wc", 7);
      call_other(toto, "set_ac", 4);
      call_other(toto, "set_hp", 45);
      move_object(toto, this_object());
}

      basket = clone_object("obj/treasure");
      call_other(basket, "set_name", "basket");
      call_other(basket, "set_weight", 1);
      call_other(basket, "set_value", 250);
      move_object(basket, dorothy);
}
}



ONE_EXIT("players/deathmonger/CASTLE/oz/wiz","north",
         "Kansas!",
         "You have entered Kansas.  Although there is nothing here, it is\n"+
         "home to Dorothy.\n",   1)
