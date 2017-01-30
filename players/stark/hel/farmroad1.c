inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Farmer's Road"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"You stand on a well rutted dirt road.  Farmers would have used this \n"+
"road to move their crops to the main roads north and west from here.\n"+
"Fenced off fields of barren lands start on the east side of the road.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/farmroad2", "north",
"/players/stark/hel/lanceroad4", "west"
});
}
