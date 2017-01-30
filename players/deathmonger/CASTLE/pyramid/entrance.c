
#include "room.h"

object sphinx, money;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
     if(!present("sphinx")){
     sphinx = clone_object("obj/monster");
       sphinx->set_name("sphinx");
       sphinx->set_level(14);
       sphinx->set_wc(18);
       sphinx->set_ac(11);
       sphinx->set_hp(210);
       sphinx->set_aggressive(1);
       sphinx->set_al(50);
       sphinx->set_short("A huge stone sphinx");
       call_other(sphinx, "set_long",
       "A large sphinx guarding the entrance to the pyramid.\n");
       move_object(sphinx, this_object());
       money = clone_object("obj/money");
       money->set_money(random(850));
       move_object(money, sphinx);
}
}

TWO_EXIT("players/deathmonger/main13","leave",
         "players/deathmonger/CASTLE/pyramid/golems","east",
         "Sphinx",
         "You stand before the entrance of the Great Pyramid.  A massive\n"+
         "sphinx stands here, guarding the entrance.\n",  1)
