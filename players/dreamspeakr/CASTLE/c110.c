inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/CASTLE/"


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Cloud Nine"+NORM;
long_desc =
    "\n"+
    "     Sunlight reflects brilliantly off the golden cobblestone \n"+
    "pathway that leads through this maginficent city in the clouds.  \n"+
    "Soft clouds float high above with a stunning blue background. \n"+
    "People move about the city busy with their their shopping.\n"+
    "A massive golden gate stands closed here.\n"
;

items = ({
    "itemname","when you look at the item this is the description you see",
    "itemname","just another example",
});

dest_dir = ({
    PATH+"c111.c","northwest",
    PATH+"c109.c","southwest",
    PATH+"c118.c","west",
});

}
