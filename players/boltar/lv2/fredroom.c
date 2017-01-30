#include "std.h"

object flint;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object boball;


    if (!flint || !living(flint)) {
	flint = clone_object("obj/monster");
	call_other(flint, "set_name", "fred");
	call_other(flint, "set_hp", 100);
call_other(flint, "set_ac", 6);
	call_other(flint, "set_wc", 10);
	call_other(flint, "set_al", -400);
	call_other(flint, "set_short", "Fred Flintstone's evil twin");
	call_other(flint, "set_long",
		   "It looks like good old Fred, but there's something different about him.\n");
	call_other(flint, "set_aggressive", 1);
call_other(flint, "set_level", 8);
	call_other(flint, "set_spell_mess1",
		   "Fred says: Ya-ba-daba-doo!!!");
	call_other(flint, "set_spell_mess2",
		   "Fred says: Ya-ba-daba-doo!!!");
	call_other(flint, "set_chance", 35);
call_other(flint, "set_spell_dam", 10);
	move_object(flint, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(350));
        move_object(money, flint);
boball = clone_object("obj/treasure");
call_other(boball, "set_id", "boball");
call_other(boball, "set_short", "A bowling ball");
call_other(boball, "set_alias", "ball");
call_other(boball, "set_long", "A bowling ball made of stone.\n");
call_other(boball, "set_value", 30);
call_other(boball, "set_weight", 4);
move_object(boball, flint);
    }
}

TWO_EXIT("players/boltar/lv2/level2room2.c", "south",
  "players/boltar/lv2/level2r1.c", "west",
  "Fred's room",
 "This room is decorated in stone age modern.  There are many heavy\n" +
 "pieces of stone furiture in here.\n", 1)
