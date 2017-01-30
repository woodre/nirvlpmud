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

     short_desc = "Hallway";
     long_desc =
"    The middle of the north hall.\n";

     items = ({
     "door","Door description",
     });

     dest_dir = ({
     ROOM + "hall1.c","north",
     ROOM + "hall3.c","south",
     ROOM + "office.c","west",
     ROOM + "med.c","east",
});

}
