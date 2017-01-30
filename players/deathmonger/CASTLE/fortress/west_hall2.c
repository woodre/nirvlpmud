#include "std.h"

object vampire;

extra_reset() {
    object treasure;
    if (!vampire || !living(vampire)) {
	vampire = clone_object("obj/monster");
	call_other(vampire, "set_name", "vampire");
	call_other(vampire, "set_alias", "undead");
	call_other(vampire, "set_level", 17);
	call_other(vampire, "set_short", "A vampire");
	call_other(vampire, "set_wc", 20);
	call_other(vampire, "set_ac", 7);
	call_other(vampire, "set_al", -500);
	call_other(vampire, "set_aggressive", 1);
	move_object(vampire, this_object());
	treasure = clone_object("obj/treasure");
	call_other(treasure, "set_id", "ring");
	call_other(treasure, "set_alias", "gold ring");
	call_other(treasure, "set_short", "A gold ring");
	call_other(treasure, "set_weight", 1);
	call_other(treasure, "set_value", 2000);
	move_object(treasure, vampire);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/deathmonger/CASTLE/fortress/west_hall1","north",
         "A crypt",
         "You are in a dark musty room.  There is a single coffin resting\n"+
         "on a pedastal in the center of the room.\n",
1)
