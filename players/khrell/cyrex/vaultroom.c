#include "std.h"

reset(arg) {
    if (!arg) {
	set_light(1);
        move_object(clone_object("players/cyrex/safe"), this_object());
    }
}

long(str) {
    if (str == "door") {
	if (call_other("room/bank", "query_door"))
	    write("The door is closed.\n");
	else
	    write("The door is open.\n");
	return;
    }
    write("You are in the backroom of the bank.\n");
    write("It has been awhile since people have set foot in here.\n");
    write("There are cobwebs and dust everywhere.\n");
    write("There is an old safe here however.\n\n");
}

short() {
    return "backroom of bank";
}

init() {
    add_action("west"); add_verb("west");
    add_action("open"); add_verb("open");
}

west() {
    if (call_other("room/bank", "query_door")) {
	write("The door is closed.\n");
	return 1;
    }
    call_other(this_player(), "move_player", "west#players/cyrex/bank");
    return 1;
}

open(str) {
    if (!str) return 0;
    if (!call_other("room/bank", "query_door"))
	return 0;
    call_other("room/bank", "open_door_inside");
    say(call_other(this_player(), "query_name") +
	" opens the door.\n");
    write("Ok.\n");
    return 1;
}
