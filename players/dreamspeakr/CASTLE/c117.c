inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     Peace and tranquility surrounds this beautiful city in \n"+
    "the clouds.  Women hurry along the cobblestone pathway from \n"+
    "shop to shop trying to get a bargin.  Tall buildings shimmer \n"+
    "in the sunlight as small clouds float overhead.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c102.c","southeast",
    PATH+"c116.c","northwest",

});

}
