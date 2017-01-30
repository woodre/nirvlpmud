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
"    The beginning of the east hall.\n";

     items = ({
     "hall","Hall description",
     });

     dest_dir = ({
     ROOM + "q1.c","north",
     ROOM + "q2.c","east",
     ROOM + "hall1.c","west",
});

}
