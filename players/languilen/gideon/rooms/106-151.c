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
maze.  The carpet factory is on the south side and the entrance\n\
to the mall can be seen at an intersection off to the west.\n";

     items = ({
  "maze","The plaza maze is just a little hedgerow maze",
});

     dest_dir = ({
        AREA+"106-152.c","east",
        AREA+"106-150.c","west",
});

}

