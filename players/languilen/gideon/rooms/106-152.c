#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Short Street";
     long_desc =
"    Along the north side of the street stretches the plaza\n\
maze.  The atrium of the carpet factory is on the south side\n\
and an intersection can be seen off to the east.\n";

     items = ({
  "sign","It describes the carpet rental prices",
});

     dest_dir = ({
        AREA+"106-153.c","east",
        AREA+"106-151.c","west",
});

}

