#include "std.h"

object champ;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!champ || !living(champ)) {
	champ = clone_object("obj/monster");
	call_other(champ, "set_name", "champion");
call_other(champ, "set_alias", "champ");
	call_other(champ, "set_level", 25);
	call_other(champ, "set_hp", 1500);
call_other(champ, "set_ac", 17);
	call_other(champ, "set_wc", 45);
	call_other(champ, "set_al", 1000);
	call_other(champ, "set_short", "Boltar's champion");
	call_other(champ, "set_long",
 "Boltar's VERY powerful champion fighter.\n");
call_other(champ, "set_aggressive", 0);
call_other(champ, "set_can_kill", 1);
call_other(champ, "init_command", "kill trixie");
	move_object(champ, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(3000));
        move_object(money, champ);
    }
}

FOUR_EXIT("players/boltar/sprooms/csroom.c", "west",
	 "players/boltar/lv1/nixonroom.c", "south",
 "players/boltar/lv1/room4.c", "north",
 "players/boltar/lv1/room3.c", "east",
        "The Champ's roomroom",
 "This room has a desk and a couple of chairs. There is a strage square light\n"+
 "flickering on the desk\n", 1)
