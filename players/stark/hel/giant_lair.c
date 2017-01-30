inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){


if(arg) return;
    set_light(1);
    set_listen("You hear nothing of interest.\n");
    set_smell("You smell nothing of interest.");
    set_search("There is nothing special about this room.");
    short_desc="Lair of the Giants";
    long_desc=
"Long\n"+
"Long line 2\n";

items=({
"item1","Showing item 1",
"item2","This would be item 2"
});

dest_dir=({
"/players/stark/hel/giant_path", "east",
"/players/stark/hel/giant_lair", "west"
});
}
