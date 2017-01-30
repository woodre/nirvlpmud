#include "/players/languilen/closed/ansi.h"
#define NAME "Languilen"
#define MOD "/players/languilen/module.c"

id(str) { return str == "doorway" || str == "door"; }

short() {
    return "A shimmering blue "+HIB+"doorway"+NORM;
}

long() { write(
"    Thin tendrils of charged particles glide across the surface of\n\
this two dimensional rectangle.  It hangs in the air about a foot above\n\
the ground.  It is about the size and shape of a door but it has no\n\
depth, so from the side it can not be seen.  The object looks out of\n\
place here and is not a natural phenomenon.  A bold adventurer might\n\
attempt to enter it.\n");
}

init() {
    add_action("enter","enter");
}

enter(str) {
    if (!id(str)) {
        notify_fail("Are you trying to enter the doorway?\n");
        return 0;
    }
    write("You step through the doorway.\n");
    this_player()->move_player("doorway#"+MOD);
    return 1;
}

get(){ return 0; }

