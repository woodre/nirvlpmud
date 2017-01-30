#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object term, rifle, money;

extra_reset(){
     if(!term){
     term = clone_object("obj/monster");
     term->set_name("conan");
     term->set_wc(20);
     term->set_level(15);
     term->set_ac(12);
      term->set_hp(250);
     term->set_short("Conan the Barbarian");
     term->set_long("The mighty warrior, Conan.\n");
     term->set_chat_chance(50);
     term->load_chat("Conan says:  Enough talk.\n");
     term->load_chat("Conan says:  I am Conan.\n");
     call_other(term, "load_chat",
     "Conan says:  The joy of life is to crush the enemy, see the children\n"+
     "run before you, and to hear the lamentation of the women.\n");
     move_object(term, this_object());
     rifle = clone_object("obj/weapon");
     rifle->set_name("sword");
     rifle->set_alias("sword");
     rifle->set_value(850);
     rifle->set_class(16);


     rifle->set_short("Sword of Conan");
     rifle->set_long("The mighty sword of Conan's forefathers.\n");
     money = clone_object("obj/money");
     money->set_money(random(100));
     move_object(money, term);
     move_object(rifle, term);
}
}

TWO_EXIT("players/deathmonger/west_hall2","east",
         "players/deathmonger/CASTLE/arnold/term","west",
         "The Terminator",
         "You enter the Arnold Schwartzeneggar Theme Park.  More Arnold\n"+
         "monsters to come.\n",  1)
