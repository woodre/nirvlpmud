#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
#define BBENT "/players/languilen/areas/city/bball/rooms/inside.c"
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Outside the Mall";
     long_desc =
"    One of three entrances to the mall opens to the west.  The\n\
entrance to the carpet factory is a bit further south.  Grand avenue\n\
continues north-south and short street heads east from here.  The\n\
plaza maze which marks the center of the buisness district is\n\
...\n";

     items = ({
  "none","Item description",
});

     dest_dir = ({
	AREA+"107-150.c","north",
        AREA+"105-150.c","south",
        AREA+"106-151.c","east",
        AREA+"106-149.c","west",
});

}
