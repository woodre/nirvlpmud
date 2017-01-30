inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    set_listen("You hear nothing of interest.\n");
    set_smell("You smell nothing of interest.");
    short_desc=HIK+"Wilderness"+NORM;
    long_desc=
/*
 1234567891123456789212345678931234567894123456789512345678961234567897*/
"Wild grass grows waist high and razor sharp.  A thin and rocky path \n"+
"winds east and west from here.  Smoke and civilization is seen in off \n"+
"to the east.  You are at one of the few breaks in a wall of trees and \n"+
"deep flora to the east.\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/forest1.c", "west",
"/players/stark/hel/hump.c", "east"
});
}
