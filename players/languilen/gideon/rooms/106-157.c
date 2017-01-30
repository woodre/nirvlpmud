#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Street";
     long_desc =
"    A low counter rests here below a large sign hanging from the\n\
roof.  There seems to be an open-air foyer to the east and an archway\n\
in the west wall that leads out to the street.\n";

     items = ({
  "sign","It describes the carpet rental prices",
});

     dest_dir = ({
        AREA+"109-158.c","east",
        AREA+"108-157.c","south",
        AREA+"109-156.c","west",
});

}

