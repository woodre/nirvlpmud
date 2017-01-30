/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/26/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "Sidewalk";
    long_desc =
    "  The Sidewalk\n\
The concrete sidewalk divides and heads off in different directions \n\
here. To the east, the sidewalk heads back into town. To the north \n\
the sidewalk continues along the western edge of town toward some \n\
buildings. There is vegetation and dirt beyond the edge of town as \n\
far as can be seen. The horizon is a sharp, flat line in the distance.\n ";

items = ({
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an easy surface to travel upon. It travels off to the north, east and south",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks like the next one from the outside",
    "east",
    "There is a large structure that towers over the rest of the buildings in the town",
    "north",
    "The sidewalk heads off toward the northwest corner of town",
    "south",
    "To the south is dry, arid land",
    "town",
    "This collection of buildings and sidewalks are thought of as a settlement",
    "horizon",
    "The horizon is the point where the sky meets the ground and can easily be seen on this smaller planet",
    "line",
    "The horizon is the point where the sky meets the ground and can easily be seen on this smaller planet",
    "structure",
    "The massive structure in the middle of town can only be faintly made out from this far edge of town",
    "vegetation",
    "These plants are meager but scrappy survivors. They have managed to survive on a frigid, desolate world that has claimed the lives of many humans",
    "dirt",
    "You are kidding right? Dirt is dirt is dirt, although this particular dirt is dry, dusty and a yellow-brown in color"
});

dest_dir = ({
    ACADIE+"room/sidewalk23.c","north",
    ACADIE+"room/sidewalk19.c","east"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
}


search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}
