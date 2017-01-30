
#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object tre, money;

extra_reset(){
     if(!present("tre")){
tre = clone_object("obj/monster");
tre->set_name("killer mimic");
tre->set_alias("chest");
tre->set_short("A large treasure chest");
call_other(tre, "set_long", "A chest full of jewels\n");
tre->set_wc(18);
tre->set_ac(11);
tre->set_al(-20);
tre->set_level(14);
tre->set_aggressive(1);
money = clone_object("obj/money");
money->set_money(random(900));
move_object(money, tre);
move_object(tre, this_object());
      }
}

ONE_EXIT("players/deathmonger/UNDERDARK/tunnel7a","east",
         "A treasure chest",
         "You can hardly believe your eyes!  There in the middle of the\n"+
         "room sits a large treasure chest, overflowing with jewels and\n"+
         "gold.  It looks like it's unguarded, too.\n",  0)
