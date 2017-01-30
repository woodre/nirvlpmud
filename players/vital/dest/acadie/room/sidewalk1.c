/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/9/01            */
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
This is the sidewalk outside the Acadie spaceport. The sidewalk is \n\
grey and leads south toward the center of the town. There is sparse \n\
vegetation around the edges of the sidewalk and the town. The terrain \n\
is flat and extends all the way to the horizon. The buildings are \n\
mostly low, unobtrusive things, except for a large structure off to \n\
the south.\n ";

items = ({
    "sidewalk",
    "The sidewalk is a light grey concrete. The construction is \n\
more primitive here in the outer systems, almost like the \n\
barbaric 20th century",
    "spaceport",
    "The Acadie spaceport is the only off-world access point on \n\
this planet. Everyone on Acadie came here via the spaceport",
    "town",
    "To the south is a small town that has grown up around the spaceport",
    "vegetation",
    "The vegetation is well suited to the arctic, tundra-like \n\
conditions that exist all over Acadie. The leaves are small, \n\
the branches are wiry, and the roots are deep",
    "edges",
    "The edges of the sidewalk are well tended and give the impression \n\
of a park",
    "terrain",
    "The terrain is broad and flat. The earth is a light yellow-grey \n\
and looks to be very dusty",
    "horizon",
    "The horizon is a very tangible line where the dome of pale blue \n\
sky meets the terrain",
    "buildings",
    "The buildings here are all very similar. They are designed to \n\
withstand the elements and serve as cheap, effective structures",
    "things",
    "You see many things when you look around",
    "structure",
    "The large structure in the center of town is easily the focal \n\
point of the town. All the avenues lead toward it and it dwarfs \n\
the nearby buildings with its presence"
});

dest_dir = ({
    ACADIE+"room/entry.c","north",
    ACADIE+"room/sidewalk2.c","south"
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
