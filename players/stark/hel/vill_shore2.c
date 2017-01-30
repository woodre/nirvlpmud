inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    set_listen("You hear nothing of interest.\n");
    set_smell("You smell nothing of interest.");
    set_search("There is nothing special about this room.");
    short_desc="Village Shore";
    long_desc=
"Long\n"+
"Long line 2\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/jetty.c", "west",
"/players/stark/hel/jetty2.c", "east",
"/players/stark/hel/farmroad2.c", "south"
});
}
