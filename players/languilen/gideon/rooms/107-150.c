#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Outside the Mall";
     long_desc =
"    .\n";

     items = ({
  "none","Item description",
});

     dest_dir = ({
	AREA+"108-150.c","north",
        AREA+"106-150.c","south",
});

}
