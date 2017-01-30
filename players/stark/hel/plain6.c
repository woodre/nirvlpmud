inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    set_listen("You hear nothing of interest.\n");
    set_smell("You smell nothing of interest.");
    set_search("There is nothing special about this room.");
    short_desc="A large open plain";
    long_desc=
"Long\n"+
"Long line 2\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/plain11.c", "north",
"/players/stark/hel/plain8.c", "east",
"/players/stark/hel/plain10.c", "west",
"/players/stark/hel/plain3.c", "south"
});
}
