#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "     Golden sunbeams reflect off the cobblestone path \n"+
    "running through the city.  Soft cloud formations drift as \n"+
    "far as the eye can see.  A colorful rainbow pierces through \n"+
    "one of the smaller clouds beside the city.  There appears \n"+
    "to be a movie theatre here with a small ticket booth.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c117.c","southeast",
    PATH+"c115.c","northwest",
});

}
