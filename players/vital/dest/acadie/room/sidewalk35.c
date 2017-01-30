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
The cold, concrete sidewalk has reached the farthest southwest corner \n\
of town and becomes a dead-end. To the far north you can faintly see \n\
the shuttles ascending and descending at the landing pad. The \n\
vegetation, dirt and environment is much more apparent here without \n\
the surrounding city to detract from it.\n ";

items = ({
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an \n\
easy surface to travel upon. It travels off to the north, east and south",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks like the \n\
next one from the outside",
    "town",
    "This collection of buildings and sidewalks are thought of as a settlement",
    "horizon",
    "The horizon is the point where the sky meets the ground and can easily \n\
be seen on this smaller planet",
    "line",
    "The horizon is the point where the sky meets the ground and can easily \n\
be seen on this smaller planet",
    "vegetation",
    "These plants are meager but scrappy survivors. They have managed to \n\
survive on a frigid, desolate world that has claimed the lives of \n\
many humans",
    "dirt",
    "You are kidding right? Dirt is dirt is dirt, although this particular \n\
dirt is dry, dusty and a yellow-brown in color",
    "corner",
    "The town sprawls in every direction",
    "landscape",
    "The collection of small, sparse vegetation and the dry, yellow-brown \n\
dirt paint a bleak and unhappy picture of life outside of the city",
    "dead-end",
    "The sidewalk does not go any farther from this point",
    "deadend",
    "The sidewalk does not go any farther from this point",
    "north",
    "The landing's and take-off's of shuttles cannot be heard, but can be \n\
faintly seen",
    "city",
    "This collection of buildings and sidewalks are thought of as a settlement",
    "alleyway",
    "This alley is dark and a horrible place to be"
});

dest_dir = ({
    ACADIE+"room/sidewalk33.c","northeast"
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
      this_player()->move_player("stumbling into darkness#/players/vital/dest/acadie/room/alley10.c");
	return 1;
}
