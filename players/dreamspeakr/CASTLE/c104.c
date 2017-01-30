inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine Square"+NORM;
long_desc =
    "\n"+
    "     In the center of this massive square, stands a large \n"+
    "golden statue of a God.  Strong and fearsome yet having a \n"+
    "certain sense of gentleness about him, he stands upon a \n"+
    "marble pedastal.  The cobblestone path winds around the \n"+
    "statue in all four directions.  There is a small gazebo \n"+
    "off to the side of the statue with a young couple sitting \n"+
    "hand in hand.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c105.c","north",
    PATH+"c103.c","south",
    PATH+"c119.c","west",
    PATH+"c118.c","east",
});

}
