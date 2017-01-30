#include "room.h"

object troll;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!troll || !living(troll)) {
	troll = clone_object("obj/monster");
        call_other(troll, "set_name", "scrag");
	call_other(troll, "set_level", 11);
	call_other(troll, "set_hp", 165);
	call_other(troll, "set_wc", 15);
	call_other(troll, "set_al", -100);
	call_other(troll, "set_short", "A scrag");
	call_other(troll, "set_long",
        "Scrags are trolls' sea-living cousins.  They are tougher than\n"+
        "trolls, though.\n");
	call_other(troll, "set_aggressive", 1);
	call_other(troll, "set_spell_mess1",
		   "The scrag says: Gurgle");
	call_other(troll, "set_spell_mess2",
		   "The scrag says: Take this! And that!");
	call_other(troll, "set_chance", 30);
	move_object(troll, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(500));
        move_object(money, troll);
    }
}

ONE_EXIT("players/deathmonger/main_sea2","west",
        "At the bottom of the sea",
        "You are in the shallow waters when you are confronted by a\n"+
        "vicious-looking troll-like sea monster.\n", 1)
