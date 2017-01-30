#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
    object orc, weapon;
    int n,i,class,value,weight;
    string w_name,alt_name;

    i = 0;
    if (!present("orc")) {
while(i<8) {
	    i += 1;
	    orc = clone_object("obj/monster.talk");
	    call_other(orc, "set_name", "orc");
	    call_other(orc, "set_alias", "dirty crap");
	    call_other(orc, "set_race", "orc");
	    call_other(orc, "set_level", random(2) + 1);
	    call_other(orc, "set_hp", 30);
	    call_other(orc, "set_ep", 1014);
	    call_other(orc, "set_al", -60);
	    call_other(orc, "set_short", "An orc");
	    call_other(orc, "set_ac", 0);
call_other(orc, "set_agressive", 1);
call_other(orc, "set_long", "An orc from Mordor\n");
	    call_other(orc, "set_a_chat_chance", 50);
call_other(orc, "load_a_chat", "Orc says: NO help to the haflings!\n");
call_other(orc, "load_a_chat", "Orc says: Where is that bloody nazgul?\n");
call_other(orc, "load_a_chat", "Orc cries: Ag Luzwig Narcle. \n");
call_other(orc, "load_a_chat", "Orc points the finger of death at you.\n");
    call_other(orc, "load_a_chat",
		"Orc says: Let's rip out his guts!\n");
	    call_other(orc, "load_a_chat", 
             "Orc says: don't let him reach the walls!!\n");
	    call_other(orc, "load_a_chat", 
         "Orc breathes foul breath upon you\n");
	    n = random(3);
	    weapon = clone_object("obj/weapon");
	    if (n == 0) {
w_name = "long knife";
		class = 5;
value = 10;
		weight = 1;
		alt_name = "knife";
	    }
	    if (n == 1) {
		w_name = "curved knife";
		class = 7;
		value = 15;
		weight = 1;
		alt_name = "knife";
	    }
	    if (n == 2) {
		w_name = "hand axe";
		class = 9;
		value = 25;
		weight = 2;
		alt_name = "axe";
	    }
	    call_other(weapon, "set_name", w_name);
	    call_other(weapon, "set_class", class);
	    call_other(weapon, "set_value", value);
	    call_other(weapon, "set_weight", weight);
	    call_other(weapon, "set_alt_name", alt_name);
	    transfer(weapon, orc);
	    call_other(orc, "init_command", "wield "+w_name);
	    move_object(orc, this_object());
	}
    }
}

ONE_EXIT("players/turk/orcs2", "east",

"A huge gathering of Orcs",
"Here is a large group of orcs ready to charge.\n", 1)
