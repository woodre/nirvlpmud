#include "/room/std.h"

object dwarf;

#undef EXTRA_MOVE1
#define EXTRA_MOVE1\
    if (dwarf && present(dwarf)) {\
	write("The generic creature bars the way !\n");\
	return 1;\
    }
#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!dwarf || !living(dwarf)) {\
	dwarf = clone_object("obj/monster");\
	call_other(dwarf, "set_name", "dwarf");\
	call_other(dwarf, "set_level", 10);\
	call_other(dwarf, "set_al", -100);\
	call_other(dwarf, "set_short", "A generic creature wearing a T-shirt that reads DWARF");\
	call_other(dwarf, "set_wc", 10);\
	call_other(dwarf, "set_ac", 1);\
	move_object(dwarf, this_object());\
    }
TWO_EXIT("/players/doctor/CASTLE/tunnel17", "north",
	 "/players/doctor/CASTLE/tunnel15", "west",
	 "Generic tunnel",
	 "In a generic tunnel.\n", 0)
