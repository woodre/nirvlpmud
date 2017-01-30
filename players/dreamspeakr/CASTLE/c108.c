inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     Small shops line this quant side of the city in the clouds. \n"+
    "The cobblestone pathway here appears to be well traveled with \n"+
    "small cracks and chips missing from it.  To the south the main\n"+
    "shop for the city seems to quite busy.  Maybe theres a sale going\n"+
    "on.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c109.c","northeast",
    PATH+"c102.c","southwest",
    PATH+"c126.c","south",
});

}
