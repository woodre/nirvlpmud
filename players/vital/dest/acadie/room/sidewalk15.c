/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   3/15/01           */
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
The concrete sidewalk is curves on around the large structure to the \n\
northwest. The structure is surrounded by a large fence and you can \n\
see a large sign on the side. The building to the southeast has an \n\
open door and there is an opening to the east The sky overhead is a \n\
light blue and filled with some slight, ribboned clouds.\n ";

items = ({
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an \n\
easy surface to travel upon. It travels off to the northeast, southeast \n\
and southwest",
    "structure",
    "This close, the structure towers over your head. It is a large \n\
colliseum or arena of some kind",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one \n\
looks like the next one from the outside",
    "sign",
    "The sign is just a bit too far around the curve of the structure",
    "fence",
    "This 3 meter high, metal fence stands about 4 meters from the base of \n\
the structure. There are large turnstile gates at regular intervals",
    "gates",
    "The gates are massive steel portals that are designed to allow \n\
pedestrian traffic to go only one direction. This gate is \n\
larger than the others in the fence that you have seen"
});

dest_dir = ({
    ACADIE+"room/sidewalk13.c","northwest",
    ACADIE+"room/sidewalk31.c","southwest",
    ACADIE+"room/sidewalk16.c","southeast"
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
