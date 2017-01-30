inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Village Church"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"You are standing in a husk of an old church.  If sun existed in this \n"+
"realm, it would beam through the open patches in the broken ceiling.  \n"+
"Long past has any sacred object been ransacked from this place.  There \n"+
"is a barren altar at the north end of the room and a deep pit in the \n"+
"center.\n";


items=({
"patches","Time and the elements have worn patches in the ceiling.",
"ceiling","Once elaborate stone and thatched roof has been near decimated.",
"altar","A slab of simple stone usable for nearly any practice.",
"pit","A shallow pit filled with ashes of previous fires"
});

dest_dir=({
"/players/stark/hel/townh.c", "north",
"/players/stark/hel/clinic.c", "east",
"/players/stark/hel/vill_green.c", "south"
});
}