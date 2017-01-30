#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
   "     This golden city in the clouds seems to burst with activity.  \n"+ 
    "People stroll happily through the city on their way from shop to \n"+
    "shop.  Everywhere the eye can see is gold, this must be the richest\n"+
    "city in Nirvana.  The sky is so blue against the clouds that billow \n"+
    "by.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c106.c","north",
    PATH+"c104.c","south",
});

}
