#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "alley";
     long_desc =
"    .\n";

     items = ({
  "none","Item description",
});

     dest_dir = ({
	AREA+"109-156.c","north",
        AREA+"107-156.c","south",
});

}
