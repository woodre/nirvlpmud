inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     The construction of a very large tower is in progress  \n"+
    "here.  Men work deligently to finish this enormous building.  \n"+
    "The people of the city walk by noticing the progress of their \n"+
    "work.  Small white clouds float just overhead. \n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c114.c","southwest",
    PATH+"c106.c","northeast",
});

}
