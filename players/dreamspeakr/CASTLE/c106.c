inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     The golden cobblestone pathway gives off a brillant hue.  \n"+
    "Soft white clouds float overhead as people stroll along the  \n"+
    "city streets.  Tall buildings seem to domaniate this section \n"+
    "of the city.  There appears to be some construction going on \n"+
    "to the southwest  A large golden gate stands closed here.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c113.c","southwest",
    PATH+"c112.c","southeast",
    PATH+"c105.c","south",
});

}
