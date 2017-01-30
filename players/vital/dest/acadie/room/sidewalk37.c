/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/25/01           */
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
The concrete, sidewalk has come to and end way out in the middle of \n\
nowhere. This far to the south there are no houses, no vegetation, \n\
nothing but miles of dirt in every direction. The entire expanse of \n\
Edmontown lies to the north.\n ";

items = ({
    "vegetation",
    "Dry, brown flora that manages to sustain life in the harsh environment here",
    "dirt",
    "This is the normal, yellow-brown dirt that filters between your fingers\n\
and drifts away in the breeze",
    "expanse",
    "The entire city of EdmonTown is spread out before you",
    "north",
    "The entire city of EdmonTown is spread out before you",
    "nowhere",
    "There is nothing but dirt surrounding you",
    "south",
    "There is nothing but dirt surrounding you",
    "west",
    "There is nothing but dirt surrounding you",
    "east",
    "There is nothing but dirt surrounding you",
    "houses",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks \n\
like the next one from the outside",
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an easy \n\
surface to travel upon. It travels off to the north, east and south",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks \n\
like the next one from the outside",
});

dest_dir = ({
    ACADIE+"room/sidewalk36.c","north"
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
