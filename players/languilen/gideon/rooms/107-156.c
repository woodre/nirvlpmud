#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Outside the Stadium";
     long_desc =
"    To the west the impressive archways that lead to the huge stadium\n\
stand open to all.  Hanging down from the arch a banner advertizes the\n\
game.  Further north along the street on the east side.\n";

     items = ({
  "none","Item description",
});

     dest_dir = ({
	AREA+"108-156.c","north",
        AREA+"106-156.c","south",
});

}
