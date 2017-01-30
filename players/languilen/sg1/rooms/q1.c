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

     short_desc = "Quarters";
     long_desc =
"    Personnel quarters.\n";

     items = ({
     "bed","bed description",
     });

     dest_dir = ({
     ROOM + "ehall.c","south",
});

}
