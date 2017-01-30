/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   4/19/01           */
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
The concrete sidewalk heads away from the structure to the northeast \n\
and toward the southwestern edge of town. This part of town seems \n\
lonely and abandoned. The buildings have spread out and there are \n\
even space where the original dirt and vegetation can be seen. The \n\
sidewalk continues on toward the southwest corner of the town \n\
of EdmonTown.\n";

items = ({
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an easy \n\
surface to travel upon. It travels off to the northeast and southwest",
    "structure",
    "This close, the structure towers over your head. It is a large colliseum \n\
or arena of some kind",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one \n\
looks like the next one from the outside",
    "edge",
    "The lines of buildings eventually come to an end to the south and southwest",
    "town",
    "The buildings have spread out away from each other",
    "sky",
    "The light "+CYN+"blue"+NORM+" expanse of the heavens seems crystal clear",
    "clouds",
    "The clouds are small, thin whisps of vapor",
    "horizon",
    "The point where the crystal blue sky meets the ground in the far distance",
    "dirt",
    "O.K. Dirt is Dirt. It looks like hundreds of pictures of dirt you might \n\
have seen before",
    "vegetation",
    "This vegetation is composed of sparse, spindly plants"
});

dest_dir = ({
    ACADIE+"room/sidewalk15.c","northeast",
    ACADIE+"room/sidewalk33.c","southwest"
  });
  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_northwest","northwest");
    add_action("move_southeast","southeast");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}

move_northwest() {
    TP->move_player("stumbles into an alley#/players/vital/dest/acadie/room/alley15.c");
    return 1;
}

move_southeast() {
    TP->move_player("stumbles into an alley#/players/vital/dest/acadie/room/alley14.c");
    return 1;
}
