/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    4/9/01            */
/*    Modified:   4/18/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                 /*universal header*/
#include "/players/vital/dest/include/dest.h"             /*area header     */

inherit "room/room";

reset(arg) {
    x = 0;
    if(!arg) { 
    set_light(1);
    short_desc = "Sidewalk";
    long_desc =
"  The Sidewalk\n\
This sidewalk is on the northwest side of town. The edge of town is \n\
directly west of the sidewalk, with dirt and vegetation beginning to \n\
encroach upon it. To the south, there is an intersection. In the \n\
near distance to the northwest you can see an odd-looking building. \n\
This area seems to be one of the suburban areas of EdmonTown. There \n\
are three homes here to the east of the sidewalk.\n ";

items = ({
    "sidewalk",
    "The sidewalk is a hard, composite material that has been fashioned from\n\
the materials readily at hand here on Acadie",
    "town",
    "This town is composed of several standard, common buildings that all look\n\
similar in form. The basic building is a low structure of stone that \n\
looks very sturdy",
    "edge",
    "The edge of town is a sharp contrast to the surrounding urban conditions. \n\
The western side of the sidewalk ends abruptly and dirt and vegetation \n\
begins. Before long the vegetation will grow back over the sidewalk",
    "east",
    "The edge of town is a sharp contrast to the surrounding urban conditions. \n\
The western side of the sidewalk ends abruptly and dirt and vegetation \n\
begins. Before long the vegetation will grow back over the sidewalk",
    "dirt",
    "The dirt is pale yellow, and very powdery",
    "vegetation",
    "The vegetation is a spindly, sparse-looking plant that has survived many \n\
storms, people and machines, only to increase and grow stronger",
    "south",
    "The sidewalk continues on and joins up with another at an intersection \n\
to the south",
    "intersection",
    "The sidewalk continues on and joins up with another at an intersection \n\
to the south",
    "distance",
    "The building you can see in the distance is different than the rest",
    "building",
    "The building you can see in the distance is different than the rest",
    "area",
    "This area near the northwestern edge of town and there seem to be many \n\
homes. The homes are the standard types of buildings that you see \n\
everywhere else in town.",
    "areas",
    "There are many areas in EdmonTown where houses have been build as a group\n\
of buildings to provide additional structural support, protection, \n\
etcetera. The need for human interaction never changes, across either \n\
time or space",
    "homes",
    "This group of homes has been built together to share structural walls, \n\
provide additional protection from crime and to allow people to \n\
interact with each other",
    "east",
    "There are many areas in EdmonTown where houses have been build as a group\n\
of buildings to provide additional structural support, protection, \n\
etcetera. The need for human interaction never changes, across either \n\
time or space"
});

dest_dir = ({
    ACADIE+"room/sidewalk27.c","north",
    ACADIE+"room/sidewalk23.c","south",
    ACADIE+"room/home7.c","northeast",
    ACADIE+"room/home6.c","east",
    ACADIE+"room/home5.c","southeast"
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
