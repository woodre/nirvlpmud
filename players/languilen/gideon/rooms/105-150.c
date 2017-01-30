#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
#define BBENT "/players/languilen/areas/city/bball/rooms/inside.c"
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Outside the Carpet Factory";
     long_desc =
"    The factory looks closed right now so the passers by just keep\n\
passing.  Further north along the west side of the street a very big\n\
building rises above the rest.\n";

     items = ({
  "building","Item description",
});

     dest_dir = ({
	AREA+"106-150.c","north",
        AREA+"104-150.c","south",
});

}
