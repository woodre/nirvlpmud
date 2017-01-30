#include "/room/room.h"

object troll;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!troll || !living(troll)) {
	troll = clone_object("obj/monster");
	call_other(troll, "set_name", "troll");
	call_other(troll, "set_level", 9);
	call_other(troll, "set_hp", 100);
	call_other(troll, "set_wc", 12);
	call_other(troll, "set_al", -60);
	call_other(troll, "set_short", "A generic creature wearing a T-shirt that reads TROLL");
	call_other(troll, "set_aggressive", 1);
	call_other(troll, "set_chance", 20);
	move_object(troll, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(500));
        move_object(money, troll);
    }
}

TWO_EXIT("/players/doctor/CASTLE/clearing", "east",
	 "/players/doctor/CASTLE/slope", "west",
        "In a generic forest",
        "You are in a big generic forest.\n", 1)
