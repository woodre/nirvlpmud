inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    add_listen("You hear nothing of interest.\n");
    add_smell("You smell nothing of interest.");
    short_desc=HIK+"Village Green"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"Sickly green crab grass sprouts from the ground below.  The expanse of \n"+
"open terrain seems nearly comfortable if it were not for the multitude \n"+
"of rocks and divets.  There are several trampled paths crushing down \n"+
"the weeds.\n";

items=({
"weeds","Only crab grass and weeds can grow here.",
"grass","Only crab grass and weeds can grow here.",
"terrian","Barren of any healthy plant life.",
"paths","Paths lead in several directions"
});

dest_dir=({
"/players/stark/hel/church.c", "north",
"/players/stark/hel/hump.c", "west",
"/players/stark/hel/vill_track.c", "east"
});
}