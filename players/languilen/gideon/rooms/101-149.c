#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
   if(arg) return;
   set_light(1);

   short_desc = "South Guardhouse";
   long_desc =
"    Here the decor is rather sparse and there is no furniture to relax\n\
on.  The walls are colored a dull gray and the brown dirt floor does\n\
nothing for the asthetics.  The one thing that can be seen from here\n\
is the busy intersection of travellers gate just outside.\n";

   items = ({
   "intersection","The opening of the guardhouse offers a perfect view of everyone passing\n\
through the gate.\n",
});

dest_dir = ({
        AREA+"101-150.c","east",
});

}
