inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     High above Nirvana a large cloud supports this enormous \n"+
    "city.  The streets are quite busy with people shopping and \n"+
    "visiting with one another.  It appears that this is a very \n"+
    "peaceful city.  Golden shimmers of light reflect off the \n"+
    "cobblestone pathway as the sun reflects off of it.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c112.c","northwest",
    PATH+"c110.c","southeast",
});

}
