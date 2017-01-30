#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
  "     Beautiful fluffy white clouds appear to support this \n"+
    "colorful city with ease.  Shimmering in the sunlight, the tall \n"+
    "buildings rest on the largest of the cloud formations.  Directly \n"+
    "north is the healers shop.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c115.c","southwest",
    PATH+"c113.c","northeast",
    PATH+"c101.c","north"
});

}
