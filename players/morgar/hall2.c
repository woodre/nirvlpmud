#include "std.h"

#undef EXTRA_INIT
#ifndef __LDMUD__ /* Rumplemintz */
#define EXTRA_INIT add_action("enter"); add_verb("enter");
#else
#define EXTRA_INIT add_action("enter", "enter");
#endif

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object mirror;

TWO_EXIT("players/morgar/hall", "west",
	 "players/morgar/hall3", "east",
	 "Hall of Gateways",
	 "This is just west of the middle of the Hall of Gateways.\n", 1)

enter() {
    write("None of the mirrors here work.\n");
    return 1;
}

extra_reset() {
    if (!mirror) {
        mirror = clone_object("players/morgar/mirror");
        call_other(mirror, "roomset", this_object());
        move_object(mirror, "players/morgar/wizworld/entry");
    }
}
