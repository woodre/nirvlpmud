#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "     Working its way to the center of the city, this cobblestone \n"+
    "pathway shimmers in the sunlight.  Just north of here sounds of \n"+
    "the weapons smith hard at work billow from his shop.  To the east \n"+
    "appears to be a large statue of some sort. \n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c115.c","west",
    PATH+"c104.c","east",
    PATH+"c121.c","north",
});

}
