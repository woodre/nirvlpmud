inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Narrow Alley"+NORM;
    long_desc=/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"You stand in a narrow alley leading southward.  Two buildings rise up \n"+
"and encapulate this small lane.  A small and old well is planted in \n"+
"the middle of the path.  To the south you can seen a well build \n"+
"building.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/vill_road1", "north",
"/players/stark/hel/post", "south",
"/players/stark/hel/well", "down"
});
}
