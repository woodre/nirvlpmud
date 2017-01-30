inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Village Track"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"The path turns into a track and eventually ends up to a solid paved \n"+
"road leading eastward.  The sprawl of the city has begun to grip the \n"+
"ground as trash is littered on the sides of a the road.  A small path \n"+
"wanders southward.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/vill_green.c", "west",
"/players/stark/hel/vill_road1.c", "east",
"/players/stark/hel/path2.c", "south"
});
}