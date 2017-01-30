#include "/room/std.h"

string rope;

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("down","down");\
    add_action("down","climb");

#undef EXTRA_LONG
#define EXTRA_LONG\
    if (str == "ring" || str == "rings") {\
	write("A generic iron ring, fastened to the generic wall.\n");\
	return;\
    }

TWO_EXIT("/players/doctor/CASTLE/tunnel2", "south",
	 "/players/doctor/CASTLE/tunnel4", "north",
	 "Generic hole",
	 "There is a generic hole here, and some generic iron rings in the generic wall.\n" +
	 "It is should be possible to pass the hole.\n", 0)

down() {
    if (!rope) {
        write("You would fall down the generic hole and possible hurt yourself generically.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "down#/players/doctor/CASTLE/tunnel8");
    return 1;
}

tie(str)
{
    if (str != "ring" && str != "rings")
        return 0;
    rope = 1;
    return 1;
}

id(str) {
    return str == "ring" || str == "rings";
}

untie(str) {
    rope = 0;
    return 1;
}

query_rope() {
    return rope;
}
