inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine Heal Shop"+NORM;
long_desc =
    "   "+
    "heal shop.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c114.c","out",
});

}
