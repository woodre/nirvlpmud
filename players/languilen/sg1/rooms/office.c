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

     short_desc = "An Office";
     long_desc =
"    An oak desk of largish size dominates the room.  The several\n\
chairs on the facing side don't compair to the leather one on the\n\
other side.  A green file cabinet stands in the corner of the room\n";

     items = ({
     "desk","It's no antique but it's a nice desk, a nameplate upon it\n\
     says -Gen Hammond-.",
     "cabinet","",
     });

     dest_dir = ({
     ROOM + "hall2.c","east",
});

}
