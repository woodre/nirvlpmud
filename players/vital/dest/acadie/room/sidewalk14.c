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
The concrete sidewalk continues alongside of the fence to the \n\
southeast of the massive structure. The sidewalk continues on \n\
along the structure to the northeast and the southwest. There \n\
is more vegetation here as the buildings thin out and the space \n\
to the southeast is composed of what could loosely be referred \n\
to as a park.\n ";

items = ({
    "park",
    "The small, brown vegetation and open space between buildings provides a sense of peace",
    "vegetation",
    "Dry, brown flora that manages to sustain life in the harsh environment here",
    "northeast",
    "The sidewalk curves off toward the northeast",
    "southwest",
    "The sidewalk curves off toward the southwest",
    "northwest",
    "This close, the structure towers over your head. It is a large colliseum or arena of some kind",
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an easy surface to travel upon. It travels off to the north, east and south",
    "structure",
    "This close, the structure towers over your head. It is a large colliseum or arena of some kind",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks like the next one from the outside",
    "sign",
    "The sign is just a bit too far around the curve of the structure",
    "fence",
    "This 3 meter high, metal fence stands about 4 meters from the base of the structure. There are large turnstile gates at regular intervals",
    "gates",
    "The gates are massive steel portals that are designed to allow pedestrian traffic to go only one direction. This gate is larger than the others in the fence that you have seen"
});

dest_dir = ({
    ACADIE+"room/sidewalk12.c","northeast",
    ACADIE+"room/sidewalk16.c","southwest"
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
