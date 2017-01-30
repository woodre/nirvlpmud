#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine Armory"+NORM;
long_desc =
    "     Brave warriors seek this highly known shop of arms.  The\n"+
    "finest metals and fabrics in the land are used to create a high\n"+
    "quality set of armor.  The counter is filled with scraps of \n"+
    "paper, material and pieces of metal.  There is a sign on the \n"+
    "back wall.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c118.c","out",
});

}
