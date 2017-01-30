#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
     "     Beauty and grace surroud this city high in the clouds.  \n"+
    "The people moving about the streets seem very happy and content \n"+
    "here.  To the north appears to be an armor shop for the Gods.  \n"+
    "Just west a large statue stands giving tribute to some great God.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c104.c","west",
    PATH+"c110.c","east",
    PATH+"c120.c","north",
});

}
