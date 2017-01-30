#include "/room/room.h"
#undef EXTRA_RESET
#define EXTRA_RESET fix_jacket();

TWO_EXIT("/players/doctor/CASTLE/wild1", "east",
	 "/players/doctor/CASTLE/clearing", "west",
	 "In a generic forest",
	 "You are in a big generic forest.\n", 1)

fix_jacket()
{
    object jacket;

    jacket = present("jacket");
    if (!jacket) {
	jacket = clone_object("obj/armor");
	call_other(jacket, "set_name", "jacket");
	call_other(jacket, "set_short", "Generic armor with JACKET written on it");
	call_other(jacket, "set_alias", "jacket");
	call_other(jacket, "set_value", 50);
	call_other(jacket, "set_weight", 2);
	call_other(jacket, "set_ac", 2);
	call_other(jacket, "set_type", "armor");
	move_object(jacket, this_object());
    }
}
