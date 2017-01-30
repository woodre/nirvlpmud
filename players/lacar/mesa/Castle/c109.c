#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
     "    Small white clouds float overhead as the sun glistens against\n"+
    "the golden cobblestone pathway.  Small shops line the street on \n"+
    "each side.  To the south appears to be a very happening little \n"+
    "shop.  Customers exiting from the shop have very pleased looks \n"+
    "on their faces.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c110.c","northeast",
    PATH+"c108.c","southwest",
    PATH+"c127.c","south",
});

}
