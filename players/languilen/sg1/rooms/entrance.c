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

     short_desc = "A Hallway";
     long_desc =
"    An elevator with huge doors and a single button end a long hallway,\n\
institutional looking hallway.  A double row of flourescent white lights do nothing to brighten the look\n\
of the gunmetal walls.  The whole place seems to vibrate slightly and a\n\
faint, deep thrumming noise gives the impression of underground machinery.\n";

     items = ({
     "door","This solid piece of metal looks impenitrable.  There are no visible\n\
means of opening it.",
     "portions","Spaced perefectly equidistant the light shed is perfectly white.",
     "celing","Pocked with strange white light.",
     "wall","hmm"
     });

     dest_dir = ({
     ROOM + "hall1.c","south",
});

}
