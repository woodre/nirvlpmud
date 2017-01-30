#include "std.h"

object davros;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object headset;
    if (!davros || !living(davros)) {
	davros = clone_object("obj/monster");
	call_other(davros, "set_name", "davros");
	call_other(davros, "set_hp", 300);
call_other(davros, "set_ac", 7);
	call_other(davros, "set_wc", 25);
	call_other(davros, "set_al", -1000);
call_other(davros, "set_whimpy");
	call_other(davros, "set_short", "Davros");
	call_other(davros, "set_long",
		   "An ugly humanoid looking creature, in some sort of mobile chair.\n");
	call_other(davros, "set_aggressive", 0);
call_other(davros, "set_level", 15);
	call_other(davros, "set_spell_mess1",
		   "Davros shocks his attacker.");
	call_other(davros, "set_spell_mess2",
		   "Davros shocks you with a blast of energy from his chair!!!");
	call_other(davros, "set_chance", 60);
	move_object(davros, this_object());
call_other(davros, "set_spell_dam", 25);
	money = clone_object("obj/money");
        call_other(money, "set_money", random(400));
        move_object(money, davros);
headset = clone_object("obj/treasure");
call_other(headset, "set_id", "headset");
call_other(headset, "set_name", "headset");
call_other(headset, "set_weight",1);
call_other(headset, "set_value",600);
        call_other(headset, "set_short", "A headset");
        move_object(headset, davros);
    }
}

ONE_EXIT("players/boltar/lv2/dalekroom.c", "east",
        "Davros room",
 "This room contains more junk like that of the other rooms around here.\n" +
 "You also notice there is running scientific equipment all around the room.\n", 1)
