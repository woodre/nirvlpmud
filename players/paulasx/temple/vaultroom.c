#include "std.h"

reset(arg) {
    if (!arg) {
        set_light(1);
        move_object(clone_object("players/paulasx/temple/safe"), this_object());
    }
}

long(str) {
    if (str == "door") {
        if (call_other("room/vault", "query_door"))
            write("The door is closed.\n");
        else
            write("The door is open.\n");
        return;
    }
    write("You are in the backroom of the vault.\n");
    write("There is a mysterious pub to the north.\n");
}

short() {
    return "Backroom of Vault";
}

init() {
    add_action("west", "west");
    add_action("north", "north");
    add_action("open", "open");
}

west() {
    if (call_other("room/bank", "query_door")) {
        write("The door is closed.\n");
        return 1;
    }
    call_other(this_player(), "move_player", "west#players/paulasx/temple/vault");
    return 1;
}

north() {
call_other(this_player(), "move_player", "north#players/paulasx/temple/wineroom");
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
