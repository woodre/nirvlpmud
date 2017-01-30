/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   4/30/01           */
/*    Realm:      Asgard            */
/************************************/

#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "The Asgard Landing Pad";
long_desc =
  "  "+short_desc+".\n\
This is a much smaller version of the N.U.T.S. Spaceport. The \n\
landing pad is similar to all the other landing pads encountered \n\
in the travel between the stars. The ground is concrete and asphalt \n\
and covered in cracks, crevises and pits. There is some kind of wall \n\
or superstructure to keep the potential for damage low. A large \n\
building with great glass doors lies to the north. In the distance, \n\
the top of a great mountain range is ensconced in the wispy clouds \n\
and darkened sky of this world.\n";

items = ({
    "pad",
    "This is where the shuttles come to land and take off",
    "shuttles",
    "These are the interstellar commuter craft that can take you to your destination",
    "spaceport",
    "At some point, you must have traveled through the heart of the transitway system",
    "clouds",
    "The clouds are whispy and provide ribboned accents to the deep "+BLU+"blue"+NORM+" sky",
    "sky",
    "The sky is a deep, dark "+BLU+"blue"+NORM+" despite the sun high in the sky",
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
    "doors",
    "The doors are nearly 2 meters high and twice that in width",
    "glass",
    "The glass is reflecting the coming and going of the shuttles",
    "north",
    "You turn to look north and see a large building with two great, glass doors",
    "structure",
    "You turn to look north and see a large building with two great, glass doors",
    "building",
    "You turn to look north and see a large building with two great, glass doors",
    "wall",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "superstructure",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "walls",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "east",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "west",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "south",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
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
