#include "std.h"

object safe, heal, scroll;
reset(arg) {
    if (!arg) {
	set_light(1);
        safe = clone_object("obj/safe");
        heal = clone_object("obj/heal");
        scroll = clone_object("players/deathmonger/QUEST/scroll");
        move_object(heal, safe);
        move_object(scroll, safe);
        move_object(safe, this_object());
    }
}

long(str) {
    if (str == "door") {
        if (call_other("players/deathmonger/CASTLE/pyramid/crypt","query_door"))
	    write("The door is closed.\n");
	else
	    write("The door is open.\n");
	return;
    }
    write("You are in the secret vault of the crypt.\n");
}

short() {
    return "secret vault of crypt";
}

init() {
    add_action("west","west");
    add_action("open","open");
}

west() {
    if (call_other("players/deathmonger/CASTLE/pyramid/crypt","query_door")) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(), "move_player",
       "west#players/deathmonger/CASTLE/pyramid/crypt");
    return 1;
}

open(str) {
    if (!str) return 0;
    if (!call_other("players/deathmonger/CASTLE/pyramid/crypt","query_door"))
	return 0;
    call_other("players/deathmonger/CASTLE/pyramid/crypt","open_door_inside");
    say(call_other(this_player(), "query_name") +
	" opens the door.\n");
    write("Ok.\n");
    return 1;
}
