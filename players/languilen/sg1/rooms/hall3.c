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

     short_desc = "A Wide Hallway";
     long_desc =
"    This north-south hallway is well lit from above by long flourescent\n\
lights.  The walls are grey steel\n";

     items = ({
     "door","Door description",
     });

     dest_dir = ({
     ROOM + "hall2.c","north",
     ROOM + "hall4.c","south",
     ROOM + "brief.c","west",
     ROOM + "control.c","east",
});

}
