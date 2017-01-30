#include "std.h"

object george,elroy,judy,jane,astro;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!astro || !living(astro)) {
	astro = clone_object("obj/monster");
	call_other(astro, "set_name", "astro");
	call_other(astro, "set_hp", 90);
call_other(astro, "set_ac", 6);
	call_other(astro, "set_wc", 7);
	call_other(astro, "set_al", 200);
	call_other(astro, "set_short", "Astro the dog");
	call_other(astro, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(astro, "set_aggressive", 0);
call_other(astro, "set_level", 5);
	move_object(astro, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, astro);
    }

    if (!jane || !living(jane)) {
	jane = clone_object("obj/monster");
	call_other(jane, "set_name", "jane");
	call_other(jane, "set_hp", 70);
call_other(jane, "set_ac", 4);
	call_other(jane, "set_wc", 4);
	call_other(jane, "set_al", 200);
	call_other(jane, "set_short", "Jane his wife");
	call_other(jane, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(jane, "set_aggressive", 0);
call_other(jane, "set_level", 3);
	move_object(jane, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, jane);
    }

    if (!judy || !living(judy)) {
	judy = clone_object("obj/monster");
	call_other(judy, "set_name", "judy");
	call_other(judy, "set_hp", 55);
call_other(judy, "set_ac", 3);
	call_other(judy, "set_wc", 4);
	call_other(judy, "set_al", 200);
	call_other(judy, "set_short", "daughter Judy");
	call_other(judy, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(judy, "set_aggressive", 0);
call_other(judy, "set_level", 3);
	move_object(judy, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, judy);
    }

    if (!elroy || !living(elroy)) {
	elroy = clone_object("obj/monster");
	call_other(elroy, "set_name", "elroy");
	call_other(elroy, "set_hp", 50);
call_other(elroy, "set_ac", 3);
	call_other(elroy, "set_wc", 5);
	call_other(elroy, "set_al", 200);
	call_other(elroy, "set_short", "his boy Elroy");
	call_other(elroy, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(elroy, "set_aggressive", 0);
call_other(elroy, "set_level", 3);
	move_object(elroy, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, elroy);
    }

    if (!george || !living(george)) {
	george = clone_object("obj/monster");
	call_other(george, "set_name", "george");
	call_other(george, "set_hp", 70);
call_other(george, "set_ac", 4);
	call_other(george, "set_wc", 6);
	call_other(george, "set_al", 200);
	call_other(george, "set_short", "Meet George Jetson");
	call_other(george, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(george, "set_aggressive", 0);
call_other(george, "set_level", 4);
	move_object(george, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(200));
        move_object(money, george);
    }

}

TWO_EXIT("players/boltar/sprooms/mtv2.c", "west",
	 "players/boltar/lv2/endless2.c", "east",
        "The Jetson's room",
        " You are still in the cartoon area, the hallway looks endless.\n", 1)
