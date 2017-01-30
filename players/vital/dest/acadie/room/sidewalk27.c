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
The concrete sidewalk continues to wind its way all around town, \n\
giving access to the very corners of the town. This far western edge \n\
of town is right up against the dirt and vegetation of the outside \n\
world. The sky and ground rush toward each other until they meet at \n\
the horizon line. The landscape outside of town is bleak and desolate.\n ";

items = ({
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an \n\
easy surface to travel upon. It travels off to the north and south",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks \n\
like the next one from the outside",
    "north",
    "The sidewalk heads off toward the northwest corner of town",
    "south",
    "To the south is a small group of buildings",
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
    "corners",
    "The town sprawls in every direction",
    "landscape",
    "The collection of small, sparse vegetation and the dry, yellow-brown \n\
dirt paint a bleak and unhappy picture of life outside of the city"
});

dest_dir = ({
    ACADIE+"room/sidewalk25.c","south",
    ACADIE+"room/sidewalk29.c","north"
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
