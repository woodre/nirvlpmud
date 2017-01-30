#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object term, rifle, money;

extra_reset(){
     if(!term){
     term = clone_object("obj/monster");
     term->set_name("terminator");
     term->set_wc(20);
     term->set_level(15);
     term->set_hp(250);
     term->set_ac(12);
     term->set_short("The Terminator");
     term->set_long("Here we see Arnold as a perfect killing machine.\n");
     term->set_a_chat_chance(20);
     term->load_a_chat("The Terminator crushes you in his hands.\n");
     term->load_a_chat("The Terminator lets off a burst of machine gun fire.\n");
     move_object(term, this_object());
     rifle = clone_object("obj/weapon");
     rifle->set_name("rifle");
     rifle->set_alias("plasma rifle");
     rifle->set_class(16);
     rifle->set_short("AL-65 Plasma Rifle in the 600kw range.\n");
     rifle->set_long("Self-explanatory, I think.\n");
     rifle->set_value(850);
     money = clone_object("obj/money");
     money->set_money(random(100));
     move_object(rifle, term);
     move_object(money, term);
}
}

ONE_EXIT("players/deathmonger/CASTLE/arnold/conan","east",
         "The Terminator",
         "The Terminator has been waiting for you here.\n",  1)
