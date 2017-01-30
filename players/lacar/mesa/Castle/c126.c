#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/CASTLE/"

inherit "room/room";

reset(arg) {
   move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/shop.c"),this_object());
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine Shop"+NORM;
long_desc =
	"Shop.\n";

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c108.c","out",
});

}
