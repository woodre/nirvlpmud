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

     short_desc = "The Den";
     long_desc =
"    The den is covered by a dark red carpet.  On one wall, faced\n\
by two chairs, is a fireplace.  The walls hold cherry bookshelves\n\
so full with books the place could double as a library.\n";

     items = ({
     "book","An impressive volume bound in white leather, read it",
     });

     dest_dir = ({
     ROOM + "hall.c","west",
});

}
