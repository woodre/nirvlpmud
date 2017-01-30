#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Grand at First Avenue";
     long_desc =
"    .\n";

     items = ({
  "sign","read",
});

     dest_dir = ({
        AREA+"110-150.c","north",
        AREA+"109-151.c","east",
        AREA+"108-150.c","south",
        AREA+"109-149.c","west",
});

}

