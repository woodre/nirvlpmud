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

     short_desc = "Med Lab";
     long_desc =
"    This large chamber houses the medical facilities for the whole\n\
underground base.\n";

     items = ({
     "bed","bed description",
     });

     dest_dir = ({
     ROOM + "hall2.c","west",
});

}
