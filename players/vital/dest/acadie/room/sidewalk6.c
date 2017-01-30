/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/19/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "The Sidewalk";
    long_desc =
    "  The Sidewalk\n\
The sidewalk continues on toward the northeast and southeast. There \n\
is a large fence surrounding the large structure to the southwest. \n\
The fence is punctuated by large turnstile gates at regular \n\
intervals around the perimeter. To the north you see an open door \n\
on a building.\n ";

items = ({
    "sidewalk",
    "The sidewalk is a conglomeration of materials to create a solid, structurally sound surface to travel upon",
    "fence",
    "The fence is all of 3 meters high and is situated 4 meters from the structure",
    "structure",
    "You see a large structure, surrounded by a large fence with turnstile gates, and a large sign on it to the northeast",
    "sign",
    "The sign is impossible to make out from this angle",
    "gates",
    "The gates are regularly spaced out along the fence. The presence of so many gates indicates that large numbers of people travel in and out of the structure",
    "door",
    "The large, wooden door is propped open by a block of wood and offers a way into the building to the north",
    "building",
    "The building has no windows or features to distinguish it from the other buildings" 
});

dest_dir = ({
    ACADIE+"room/sidewalk5.c","northwest",
    ACADIE+"room/sidewalk8.c","southeast",
    "","north"
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
    write("The ticket office is closed for the season.\n");
    return 1;
}