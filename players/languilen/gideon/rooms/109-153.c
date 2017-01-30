#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Main at First Avenue";
     long_desc =
"    .\n";

     items = ({
  "sign","The sign is artisticly crafted and very colorful but not too easy to read",
});

     dest_dir = ({
        AREA+"107-153.c","north",
        AREA+"106-154.c","east",
        AREA+"105-153.c","south",
        AREA+"106-152.c","west",
});

}

