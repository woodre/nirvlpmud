/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "A Hallway Junction";
     long_desc =
"    A short eastern wing branches from the main north-south hallway here.\n\
To the west there looks to be living quarters of some kind.\n";

     items = ({
     "door","Door description",
     });

     dest_dir = ({
     ROOM + "entrance.c","north",
     ROOM + "hall2","south",
     ROOM + "gq.c","west",
     ROOM + "ehall.c","east",
});

}
