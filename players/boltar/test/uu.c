#include "std.h"

object it;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!it || !living(it)) {
	it = clone_object("obj/testmon.c");
	call_other(it, "set_name", "it");
	call_other(it, "set_hp", 90);
call_other(it, "set_ac", 4);
	call_other(it, "set_wc", 0);
	call_other(it, "set_al", 200);
	call_other(it, "set_short", "An it");
	call_other(it, "set_long",
		   "It looks like a lot of hair wearing a hat.\n");
	call_other(it, "set_aggressive", 0);
call_other(it, "set_level", 7);
	call_other(it, "set_spell_mess1",
		   "It says: eeebeeenneetoi.");
	call_other(it, "set_spell_mess2",
		   "It says: eebbeeeeteeneetoitu.");
	call_other(it, "set_chance", 99);
        call_other(it, "set_spell_dam", 40);
	move_object(it, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, it);
    }
}

TWO_EXIT("players/boltar/lv1/secserv.c", "west",
	 "players/boltar/lv1/room2.c", "north",
        "The It room",
   "You notice that it is a bit darker in here. You  have entered\n"+
   "a passageway with an ached ceiling that continues the style of the enterance\n"+
   "hall.  You notice that the passageway goes around in a quarter circle\n"+
   "so upon coming to the end you will be facing a different direction.\n", 1)
