/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   4/29/01           */
/*    Realm:      Multnomah         */
/************************************/

#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "The Aquitaine Landing Pad";
long_desc =
  "  "+short_desc+".\n\
This is a much smaller version of the N.U.T.S. Spaceport. The \n\
landing pad is similar to all the other landing pads encountered \n\
in the travel between the stars. The ground is concrete and asphalt \n\
and covered in cracks, crevises and pits. There is some kind of wall \n\
or superstructure to keep the potential for damage low. The ticket \n\
building is located to the southwest.\n";

items = ({
    "pad",
    "This is where the shuttles come to land and take off",
    "shuttles",
    "These are the interstellar commuter craft that can take you to your destination",
    "spaceport",
    "At some point, you must have traveled through the heart of the transitway system",
    "stars",
    "After looking at the stars, loneliness settles in for your home",
    "sky",
    "You search the heavens for incomming shuttles",
    "concrete",
    "This loosely resembles the mixture of sand, quicklime and other particulate matter that you are used to seeing",
    "asphalt",
    "The black tarmac is covered again and again with cracks and crevises",
    "crack",
    "The cracks have been covered and recreated by the constant shuttle flights",
    "cracks",
    "The cracks have been covered and recreated by the constant shuttle flights",
    "crevise",
    "The crevises are the results of water falling as rain, freezing and expanding in cracks, pushing them farther apart",
    "crevise",
    "The crevises are the results of water falling as rain, freezing and expanding in cracks, pushing them farther apart",
    "southwest",
    "You turn to look southwest and see a smaller, building with a large flag",
    "structure",
    "You turn to look southwest and see a smaller, building with a large flag",
    "building",
    "You turn to look southwest and see a smaller, building with a large flag",
    "wall",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the southwest",
    "walls",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the southwest",
    "east",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the southwest",
    "west",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the southwest",
    "south",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the southwest",
    "flag",
    "A large piece of cloth with three large bands. The top is "+HIR+"red, "+NORM"the middle is "+HIW+"white"+NORM+", and the bottom is "+HIB+"blue"+NORM+""
});

dest_dir = ({
});

  }
}

init() {
  add_action("search_me","search");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You furiously search the "+str+" but find nothing.\n");
}
