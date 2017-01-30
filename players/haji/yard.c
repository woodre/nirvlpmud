#include "room.h"
object beggar;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

/*
 * Make these arrays global, so they only have to be initialized once.
 */
string chat_str, a_chat_str, function, type, match;

extra_reset() {
    no_castle_flag = 1;
    if (!present("knife")) {
        string weapon;
        weapon = clone_object("obj/weapon");
        call_other(weapon, "set_name", "knife");
        call_other(weapon, "set_class", 5);
        call_other(weapon, "set_value", 8);
        call_other(weapon, "set_weight", 2);
	move_object(weapon, this_object());
    }
    if (!beggar) {
	beggar = clone_object("obj/monster");
	call_other(beggar, "set_name", "hank the homeless honky");
call_other(beggar, "set_alias","hank");
	call_other(beggar, "set_level", 3);
	call_other(beggar, "set_al", 200);
	call_other(beggar, "set_race", "human");
	call_other(beggar, "set_long",
		   "A really filthy looking poor homeless honky.\n");
	call_other(beggar, "set_hp", 30);
	move_object(beggar, this_object());
	if (!function) {
	    function = allocate(1);
	    type = allocate(1);
	    match = allocate(1);
	    function[0] = "give_beggar";
	    type[0] = "gives";
	}
	if (!a_chat_str) {
	    a_chat_str = allocate(5);
	    a_chat_str[0] =
		"Hank says: Please, give money to a poor honky!\n";
	    a_chat_str[1] =
		"Hank says: Why can't I find any money ?\n";
	    a_chat_str[2] =
		"Hank says: Gimme your money or I'll mug You !\n";
    a_chat_str[3] =
"Hank says: Hey that box is my home, leave it alone!!!!\n";
   a_chat_str[4] =
   "Hank says: Do you have any spare boxes?  I want to expand my home.\n";
	}
call_other(beggar,"set_match",this_object(),function,type,match);
     if(!chat_str) {
	    chat_str = allocate(1);
	    chat_str[0] = "Hank says: Why do you do this to me ?\n";
	}
	call_other(beggar, "load_chat", 1, chat_str);
	call_other(beggar, "load_a_chat", 50, a_chat_str);
    }
}

THREE_EXIT("room/vill_road1", "south",
  "room/alley", "west",
	 "room/pub2", "east",
	 "Small yard",
	 "A small yard surrounded by houses.\n", 1)

give_beggar(str) {
    int money;
    string who;

    say("Hank says: Is that all you're gonna give me?  God what a cheap son of a bitch!!!!\n");
    if (sscanf(str, "%s gives you %d gold coins.", who, money) != 2)
	return;
    if (call_other(beggar, "query_money") >= 12 &&
	    environment(beggar) == this_object()) {
	call_other(beggar, "init_command", "east");
	call_other(beggar, "init_command", "buy beer");
	call_other(beggar, "init_command", "drink beer");
	call_other(beggar, "init_command", "west");
    }
}

