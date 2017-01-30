#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine Wepons"+NORM;
long_desc =
    "     In the center of this shop is a large fire pit.  The smoke \n"+
    "from it billows out a large chimney in the ceiling.  Customers \n"+
    "stand in line to get their weapons made by the best sword master\n"+
    "in the realm.  There is a large sign on the back wall.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c119.c","out",
});

}
