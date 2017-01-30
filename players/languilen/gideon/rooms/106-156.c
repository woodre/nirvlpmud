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
"    .\n";

     items = ({
  "sign","It describes the carpet rental prices",
});

     dest_dir = ({
        AREA+"107-156.c","north",
        AREA+"106-155.c","west",
});

}

