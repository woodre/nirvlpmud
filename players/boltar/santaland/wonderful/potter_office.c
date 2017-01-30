#include "std.h"

object potter;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!potter || !living(potter)) {
	potter = clone_object("obj/monster");
	call_other(potter, "set_name", "potter");
	call_other(potter, "set_hp", 140);
call_other(potter, "set_ac", 8);
	call_other(potter, "set_wc", 12);
	call_other(potter, "set_al", -500);
	call_other(potter, "set_short", "Old Mr. Potter ");
	call_other(potter, "set_long",
   "Mr. Potter owns just about the whole town, accept for what George\n"+
   "Bailey has built. He's in a wheelchair, but he is rich enough to do what\n"+
   "he wants.\n");
	call_other(potter, "set_aggressive", 0);
call_other(potter, "set_level", 9);
	call_other(potter, "set_spell_mess1",
		   "Potter says: You saved the building and loan George, I saved the rest..");
	call_other(potter, "set_spell_mess2",
    "Potter says: I say we close this building and loan.");
	call_other(potter, "set_chance", 30);
	move_object(potter, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, potter);
    }
}

ONE_EXIT("players/boltar/santaland/wonderful/bank.c", "north",
        "The Potter's office",
"An office inside the bank. This is where Old Mr. Potter runs his affiars.\n"+
"He has just decided to raise the rent on the shacks he rents the poorer\n"+
"people in town.  George Bailey helps those people and it bothers him.\n"+
"No matter what Potter does he just can't win.\n", 1)
