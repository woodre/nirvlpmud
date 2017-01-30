
/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/16/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"               /*area header*/

inherit "room/room";

reset(arg) {
    if(!arg) {
    set_light(1);
    short_desc = "Sidewalk";
    long_desc =
    "  The Sidewalk\n\
The sidewalk continues north and south through the town. The concrete \n\
is cold and the buildings are becoming more crowded and filled with \n\
more and more people who live here. To the south is the massive, steel, \n\
colliseum-like structure that dominates the surrounding, low, stone \n\
buildings.\n";

items = ({
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+" concrete runs north and south \n\
through town",
    "concrete",
    "This is the cold, "+BOLD+BLK+"grey"+NORM+" substance that people \n\
walk on",
    "town",
    "This frontier town is composed of many smaller, low, stone buildings \n\
and a large building in the center",
    "buildings",
    "The buildings are all low, made out of the same "+BOLD+BLK+"grey\n\
"+NORM+" stone, and crowd up against one another",
    "people",
    "The people are bundled up against the cold and never seem to vary \n\
from their task and destinations",
    "here",
    "You are outside, on the sidewalk, between buildings near the center \n\
of town",
    "south",
    "The sidewalk continues on and a large structure nearly fills the \n\
field of vision",
    "structure",
    "The structure is large and nearly fills the field of vision. It is \n\
tall, and curves off to the east and west",
    "north",
    "The sidewalk continues on north and you can see shuttles coming and \n\
going in the distance",
    "shuttles",
    "The great commercial shuttles of the stars"
});

dest_dir = ({
    ACADIE+"room/sidewalk3.c","north",
    ACADIE+"room/sidewalk5.c","south",
    ACADIE+"room/home1.c","east",
    ACADIE+"room/alley1.c","west"
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
