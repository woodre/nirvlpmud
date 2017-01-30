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

     short_desc = "City Streets";
     long_desc =
"    Wide sidewalks front the buisinesses on both sides of this\n\
neiborhood street.\n";

     items = ({
     "sidewalks","",
     "businesses","",
     });

     dest_dir = ({
     ROOM + "street3.c","east",
     ROOM + "street1.c","west",
});

}
