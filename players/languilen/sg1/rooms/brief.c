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

     short_desc = "Briefing Room";
     long_desc =
"    Here the members of the SOC teams recieve thier operation\n\
instructions.  A long table surrounded by chairs barely leaves\n\
room to walk by.  A large diagram is affixed to the far wall.\n";

     items = ({
     "table","Nothing special, just a long rectangular wooden table",
     "chairs","Four legs, made of wood, slightly cushioned, yes the're chairs",
     "diagram","It's like a pincushion.  There's a ball in the middle\n\
with lines coming out ending with another little ball, all in different\n\
lengths and directions.  It looks rediculus",
     });

     dest_dir = ({
     ROOM + "hall3.c","east",
});

}
