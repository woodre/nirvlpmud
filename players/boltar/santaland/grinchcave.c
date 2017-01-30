#include "std.h"

object grinch;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!grinch || !living(grinch)) {
	grinch = clone_object("obj/monster");
	call_other(grinch, "set_name", "grinch");
	call_other(grinch, "set_hp", 140);
call_other(grinch, "set_ac", 8);
	call_other(grinch, "set_wc", 12);
	call_other(grinch, "set_al", -500);
	call_other(grinch, "set_short", "The Grinch who stole Christmas");
	call_other(grinch, "set_long",
   "It's the good old grinch himself.\n");
	call_other(grinch, "set_aggressive", 0);
call_other(grinch, "set_level", 9);
	call_other(grinch, "set_spell_mess1",
		   "Grinch says: I hate Christmas.");
	call_other(grinch, "set_spell_mess2",
	   "The Grinch says: I realy hate Christmas, I'm going to steal it from you all!");
	call_other(grinch, "set_chance", 30);
	move_object(grinch, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, grinch);
    }
}

ONE_EXIT("players/boltar/santaland/snow2.c", "down",
        "The Grinch room",
    "You have climbed up into the lair of the Grinch.\n"+
    "It's not much more than a simple cave. It's dark and lonely up here.\n"+
    "It looks like someone has been planing something here\n", 1)
