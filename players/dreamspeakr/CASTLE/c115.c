inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     The golden cobblestone path glimmers in the sunlight.  \n"+
    "Soft white clouds float above this city in the heavens.  High \n"+
    "above Nirvana people move about on their way to the shops and \n"+
    "stores within the confines of this enoumous cloud.  There is \n"+
    "a golden gate here, but it appears to be closed.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c116.c","southeast",
    PATH+"c114.c","northeast",
    PATH+"c119.c","east",
});

}
