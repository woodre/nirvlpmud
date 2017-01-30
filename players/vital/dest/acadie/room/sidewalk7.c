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
The concrete sidewalk continues on toward the northwest and south. \n\
The fence around the massive structure to the southeast continues \n\
and you can see a sign on the side of the structure. The buildings \n\
opposite of the structure are not nearly as tall and their style \n\
is radically different. This far into town there is none of the \n\
vegetation that is found elsewhere.\n ";

items = ({
    "concrete",
    "This is a conglomeration of materials mixed together to form a stable surface for pedestrian traffic",
    "sign",
    "The sign is just a bit too far around the curve of the structure",
    "sidewalk",
    "The concrete sidewalk continues on toward the northeast and the south",
    "northeast",
    "To the northeast you can see that the sidewalk curves on around the structure",
    "south",
    "To the south you can see that the sidewalk curves on around the structure",
    "buildings",
    "The buildings are small, stone structures, that often do not have windows or visible doors",
    "structure",
    "The massive structure to the southwest is nearly four stories tall and surrounded by a 3 meter high fence",
    "fence",
    "The 3 meter fence stands about 4 meters away from the base of the structure and is punctuated with turnstile gates",
    "town",
    "The town is full of low, stone buildings",
    "vegetation",
    "There is no vegetation here in town"
});

dest_dir = ({
    ACADIE+"room/sidewalk5.c","northeast",
    ACADIE+"room/sidewalk9.c","southwest"
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
