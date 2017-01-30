/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   4/18/01           */
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
The concrete sidewalk heads away from the structure to the east and \n\
toward the western edge of town. The low, stone buildings in the city \n\
are crowding the sidewalk here. The light blue sky has strands of \n\
clouds strung across it like ribbons. In the distant west you can see \n\
the horizon briefly.\n";

items = ({
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an \n\
easy surface to travel upon. It travels off to the north, southeast \n\
and southwest",
    "structure",
    "This close, the structure towers over your head. It is a large colliseum \n\
or arena of some kind",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks like the \n\
next one from the outside",
    "edge",
    "The lines of buildings eventually come to an end to the east",
    "town",
    "Everywhere around you are buildings that make up this town",
    "sky",
    "The light "+CYN+"blue"+NORM+" expanse of the heavens seems crystal clear",
    "clouds",
    "The clouds are small, thin whisps of vapor",
    "horizon",
    "The point where the crystal blue sky meets the ground in the far distance",
    "west",
    "The point where the crystal blue sky meets the ground in the far distnace"
});

dest_dir = ({
    ACADIE+"room/sidewalk19.c","west",
    ACADIE+"room/sidewalk11.c","east"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_north","north");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}

move_north() {
    write("You stumble blindly into the dark alley.\n");
    this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/alley5.c");
	return 1;
}
