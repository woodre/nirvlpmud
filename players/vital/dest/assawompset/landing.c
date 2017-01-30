/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   4/30/01           */
/*    Realm:      Assawompsset      */
/************************************/

#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "The Assawompset Landing Pad";
long_desc =
  "  "+short_desc+".\n\
This is a much smaller version of the N.U.T.S. Spaceport. The \n\
landing pad is similar to all the other landing pads encountered \n\
in the travel between the stars. The ground is concrete and asphalt \n\
and covered in cracks, crevises and pits. There is some kind of wall \n\
or superstructure to keep the potential for damage low. The entire \n\
western side of the structure is composed of a large, bright building. \n\
The eastern side of the compound is a low building that seems to shimmer.\n";

items = ({
    "pad",
    "This is where the shuttles come to land and take off. On closer \n\
inspection you notice that there is sharp divided line down the \n\
middle of the pad",
    "line",
    "The line is created by the extreme difference in the quality of \n\
the landing pad surface",
    "shuttles",
    "Most of these are the interstellar commuter craft that can take \n\
you to your destination. On the other side of the dividing line the \n\
shuttles have a very different look",
    "spaceport",
    "At some point, you must have traveled through the heart of the \n\
spaceport shuttle system",
    "stars",
    "After looking at the stars, loneliness settles in for your home",
    "sky",
    "You search the heavens for incomming shuttles",
    "concrete",
    "This loosely resembles the mixture of sand, quicklime and other particulate matter that you are used to seeing",
    "asphalt",
    "The black tarmac is covered again and again with cracks and crevises \n\
on this side of the landing pad",
    "crack",
    "The cracks on this side of the landing pad have been covered and \n\
recreated by the constant shuttle flights",
    "cracks",
    "The cracks have been covered and recreated by the constant \n\
shuttle flights",
    "crevise",
    "The crevises are the results of water falling as rain, freezing and expanding in cracks, pushing them farther apart",
    "crevise",
    "The crevises are the results of water falling as rain, freezing and expanding in cracks, pushing them farther apart",
    "west",
    "You turn to look west and see a large, brightly lit building where \n\
many casually dressed passengers are heading",
    "structure",
    "You turn to look west and see a large, brightly lit building where \n\
many casually dressed passengers are heading",
    "building",
    "You turn to look west and see a large, brightly lit building where \n\
many casually dressed passengers are heading",
    "passengers",
    "These are people who travel between the stars on the commercial \n\
shuttles of the world",
    "wall",
    "The four meter high wall circles the landing pad in every direction, except for the structures to the east and west",
    "walls",
    "The four meter high wall circles the landing pad in every direction, except for the structures to the east and west",
    "east",
    "The building to the east is low and shimmers behind the protection of \n\
some unknown force",
    "north",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "south",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the northeast",
    "flag",
    "A large piece of cloth with many stripes of "+RED+"red, "+NORM+"white, \
"+BLU+"blue"+NORM+" and stars \nspread out across the whole thing,
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
