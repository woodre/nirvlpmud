#include "std.h"

object creeper;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!creeper || !living(creeper)) {
	creeper = clone_object("obj/monster");
	call_other(creeper, "set_name", "creeper");
	call_other(creeper, "set_hp", 90);
call_other(creeper, "set_ac", 4);
	call_other(creeper, "set_wc", 6);
	call_other(creeper, "set_al", 200);
	call_other(creeper, "set_short", "A Dark Creeper");
	call_other(creeper, "set_long",
    "A small creature that stays away from the light.\n");
	call_other(creeper, "set_aggressive", 0);
call_other(creeper, "set_level", 7);
	move_object(creeper, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, creeper);
    }
}

TWO_EXIT("players/boltar/lv1/secserv.c", "west",
	 "players/boltar/lv1/room2.c", "north",
        "The It room",
   "You notice that creeper is a bcreeper darker in here. You  have entered\n"+
   "a passageway wcreeperh an ached ceiling that continues the style of the enterance\n"+
   "hall.  You notice that the passageway goes around in a quarter circle\n"+
   "so upon coming to the end you will be facing a different direction.\n", 1)
