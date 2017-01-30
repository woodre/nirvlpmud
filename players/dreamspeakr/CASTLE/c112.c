inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     Strolling along the cobblestone ladies stop and view the \n"+
    "items in shop windows.  The buildings on this side of the city \n"+
    "seem a little smaller then those on the western side.  To the \n"+
    "north is a small tavern. \n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c106.c","northwest",
    PATH+"c111.c","southeast",
    PATH+"c129.c","north",
});

}
