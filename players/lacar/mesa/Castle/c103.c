#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "     Through the center of this wonderful city, tall golden \n"+
    "buildings line the road.  Just to the north seems to be a \n"+
    "large golden statue of some sort.  People scurry about in a \n"+
    "rush to finish their shopping.  The wind blows softly as sounds\n"+
    "of birds singing fill the air. \n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c104.c","north",
    PATH+"c102.c","south",
});

}
