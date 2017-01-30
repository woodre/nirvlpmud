inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Narrow Path"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"A narrow path wanders up a hill towards the main path of the village.\n"+
"To the northwest you can see the crumbling steeple of the church.  \n"+
"Sickly crab grass grabs at your feet underneith.  The path has been \n"+
"beaten down due to the constant stream of merchants running to the \n"+
"church for any sorts of reasons.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/vill_track.c", "north",
"/players/stark/hel/path1.c", "south"
});
}
