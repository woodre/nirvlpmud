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
    if(arg) return;
    set_light(1);
    short_desc = "Sidewalk";
    long_desc =
    "  The Sidewalk\n\
The concrete sidewalk continues on around the massive structure \n\
both northeast and to the south. Directly north is a slight opening \n\
between some of the buildings. There is a large fence in front of \n\
the structure and a sign mounted high on the western side.\n ";

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
    "opening",
    "The buildings have a space between them and you could enter it"
});

dest_dir = ({
    ACADIE+"room/sidewalk7.c","northeast",
    ACADIE+"room/sidewalk11.c","south"
  });

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
    this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/alley8.c");
	return 1;
}
