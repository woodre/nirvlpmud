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

     short_desc = "The Foyer";
     long_desc =
"    This room is the entrance to a large and elegant home.\n\
High vaulted ceilings with arched doorways, satillo tile, the\n\
trappings of extravagance.  The white walls hold pictures of\n\
many distinguished gentlimen.  In the center of the room upon\n\
a white pedistal rests a large book.\n";

     items = ({
     "tile","",
     "book","An impressive volume bound in white leather, read it",
     });

     dest_dir = ({
     ROOM + "hall.c","east",
     ROOM + "street3.c","west",
});

}
