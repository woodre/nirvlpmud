#include "room.h"
#include "/players/coldwind/ansi.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object term, rifle, money;

extra_reset(){
     if(!term){
     term = clone_object("obj/monster");
     term->set_name("conan");
     term->set_wc(26);
     term->set_level(18);
     term->set_ac(15);
     term->set_hp(400);
 term->set_short("Conan the "+BOLD+"Barbarian"+NORM+"");
     term->set_long("The mighty warrior, Conan.\n"+
                    "A tall muscular man is standing here. He is totally naked,\n"+
                    "but his body is covered with strange dark paintings. The\n"+
                    "warrior seems annoyed to see you.\n");
     term->set_chat_chance(20);
     term->load_chat("Conan says:  Enough talk.\n");
     term->load_chat("Conan says:  I am Conan.\n");
     call_other(term, "load_chat",
     "Conan says:  The joy of life is to crush the enemy, see the children\n"+
     "run before you, and to hear the lamentation of the women.\n");
term->set_chance(40);
  term->set_spell_dam(40);
  term->set_spell_mess1(""+BOLD+"Conan overwhelms his enemy with powerful attacks."+NORM+"\n");
  term->set_spell_mess2(""+BOLD+"Conan overwhelms you with powerful attacks."+NORM+"\n");
     move_object(term, this_object());
     rifle = clone_object("obj/weapon");
     rifle->set_name("sword");
     rifle->set_alias("sword");
    rifle->set_value(1000);
   rifle->set_class(18);


     rifle->set_short("Sword of Conan");
 rifle->set_long("The mighty sword of Conan's forefathers.\n"+
                 "It's a long double edged blade made of steel. The hilt looks\n"+
                 "simple with some pieces of leather wrapped around it.\n");
     money = clone_object("obj/money");
money->set_money(2000 + random(1000));
     move_object(money, term);
     move_object(rifle, term);
}
}

TWO_EXIT("players/deathmonger/west_hall2","east",
         "players/deathmonger/CASTLE/arnold/term","west",
         "The Terminator",
         "You enter the Arnold Schwartzeneggar Theme Park.  More Arnold\n"+
         "monsters to come.\n",  1)


weapon_hit(attacker) {
    int dam;
    	dam = random(20);
	if(dam < 5)
	    return 0;
	if(dam < 10)
            say("You swing the mighty sword.\n");
	else if(dam < 15)
            say("The mighty sword find its way through your enemy's defenses.\n");
	else if(dam < 19)
         say(""+HIR+"The sword tastes the blood of your enemy."+NORM+"\n");
	else if(dam == 20) {
	    tell_room(this_object(),
     ""+HIR+"Blood pours from the deep wounds..."+NORM+"\n");
	    dam = dam + random(15);
	    
}

	return dam;
    }
