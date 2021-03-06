/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/5/01            */
/*    Realm:      Trondelag         */
/************************************/

#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "The Aquitaine Landing Pad";
long_desc =
  "  "+short_desc+".\nThis is a much smaller version of the \n\
N.U.T.S. Spaceport. The landing pad is similar to all the other \n\
landing pads encountered in the travel between the stars. The ground \n\
is concrete and asphalt and covered in cracks, crevises and pits. \n\
There is some kind of wall or superstructure to keep the potential \n\
for damage low. The ticket building is located to the east.\n";

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
    "east",
    "You turn to look east and see a smaller, building with a large flag",
    "structure",
    "You turn to look east and see a smaller, building with a large flag",
    "building",
    "You turn to look east and see a smaller, building with a large flag",
    "wall",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the east",
    "walls",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the east",
    "west",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the east",
    "south",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the east",
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
