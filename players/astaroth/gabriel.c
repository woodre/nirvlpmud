#include        "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET more_reset();
ONE_EXIT("players/astaroth/gdmusic2", "north",
           "So?",
           "Meet Peter Gabriel, former singer for Genesis and one of\n" +
           "today's top solo artists.  If Peter isn't here, he's probably\n" +
           "out doing a benefit for aparteid.\n",
           1)
 
 
object monster, weapon, armor, money;
 
more_reset(){
if (!monster || !living(monster)) {
monster = clone_object ("obj/monster");
call_other (monster, "set_name", "gabriel");
call_other (monster, "set_alias", "peter");
call_other (monster, "set_level",15);
call_other (monster, "set_hp",300 + random(100));
call_other (monster, "set_al",500);
call_other (monster, "set_race","human");
call_other (monster, "set_short","Peter Gabriel");
call_other (monster, "set_long", "Peter looks kind of pissed about song theft.\n");
call_other (monster, "set_ac",12);
call_other (monster, "set_wc",17);
call_other (monster, "set_aggressive",0);
call_other (monster, "set_chance", 30);
call_other (monster, "set_spell_mess2", "Red rain is falling down over you!");
call_other (monster, "set_spell_mess1","Peter shocks a monkey!\n");
call_other (monster, "set_spell_dam", 25);
 
{
  weapon = clone_object("obj/weapon");
call_other (weapon,"set_name", "sledgehammer");
call_other (weapon,"set_alias", "sledge");
call_other (weapon,"set_short","Sledgehammer");
call_other(weapon, "set_long", "Looks really good for popping weasels.\n");
call_other (weapon,"set_class",16);
call_other (weapon,"set_weight",4);
call_other (weapon,"set_value", 1000);
call_other (weapon,"set_hit_func", this_object());
transfer (weapon, monster);
transfer (monster, this_object());
}
}
}
weapon_hit (attacker) {
	if(call_other(attacker,"id","third base")) {
	   write("The sledgehammer pops the weasel.\n");
	   say("The weasel is popped.\n");
	   return 42;
	}
	return 0;
}
