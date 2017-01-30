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

     short_desc = "A Wide Hall";
     long_desc =
"    A long dining table streches through the middle of this\n\
room.  On the left a spiral staircase curls its way upstairs.\n\
A soft light shines in from the north atrium and through the\n\
doorway east can be seen a comfortable looking den.\n";

     items = ({
     "book","An impressive volume bound in white leather, read it",
     });

     dest_dir = ({
     ROOM + "atrium","north",
     ROOM + "den.c","east",
     ROOM + "foyer.c","west",
});

}
