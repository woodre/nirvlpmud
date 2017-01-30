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
"A path wanders slowly up a hill towards the church.  Sickly crab \n"+
"grass grabs at your feet underneith.  The path has been beaten down \n"+
"due to the constant stream of merchants running to the church for any \n"+
"sorts of reasons.  To the east an official and well built building \n"+
"can be seen.  There is a well paved road at the bottom of the hill.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/path2.c", "north",
"/players/stark/hel/lanceroad3.c", "south"
});
}
