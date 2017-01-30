#include <ansi.h>
#define NAME "Valen"
#define DEST "room/south/sislnd1"

id(str) { return str == "castle"; }

short() {
    return "Castle of " + NAME;
}

long() {
    write("This is the " + short() + ".\n");
    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("The castle is now open.\n");
}

init() {
    add_action("enter","enter");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    " walks into the castle.\n");
    this_player()->move_player(
    "walks into the castle#/players/valen/area/catacombs/rooms/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

reset(arg) {
    if (arg)
        return;
    move_object(this_object(), DEST);
}

is_castle(){return 1;}