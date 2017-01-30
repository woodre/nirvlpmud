#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("stfolk")){ 
    move_object(clone_object("players/softly/algiers/mobs/folks.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Algiers";
  long_desc ="\n\
  A broad dirt road runs through the center of town. The\n\
townspeople move about easily, greeting one another.  To\n\
the west is a small school yard beyond which is a one room\n\
wooden schoolhouse.  East is a blue building streaked with pink,\n\
white, yellow, and other colors giving the effect of a french\n\
impressionist painting.  A prominent sign hangs out in front.\n\
North and south the commercial center of town continues.  In\n\
the distace to the far northwest a white steeple can be seen.\n";

  items = ({
    "tables",
    "Wooden picnic tables that have seen better days", 
    "door", 
    "The door below the sign is white.  It is open",
    "toys", 
    "A rubber ball, several small metal cars, and\n\
a naked dirty doll",
    "papers",
    "Wide lined paper, some covered with large\n\
poorly written letters",
    "road",
    "The brown earthen road is very dusty",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple.",
    "townspeople",
    "People of all ages and animals walk to and fro on the road",
    "steeple",
    "A white steeple rises in the distance",
    "building",
    "The blue streaked building seems as if it had been\n\
dipped in water when the paint was still wet.  There is\n\
a sign above the white front door",
    "yard",
    "A small school has a yard in front littered with toys\n\
and half finished papers.  Several small tables are near\n\
the door.",
    "schoolhouse",
    "Beyond the school yard a wooden building barely\n\
contains the voices of the children within",
    "awning",
    "The white metal awning shades the front door",
    "sign",
    "Belle's Parlor",
});

  dest_dir = ({
    "/players/softly/algiers/rooms/schlyrd.c","west",
    "/players/softly/algiers/rooms/bellep.c","east",
    "/players/softly/algiers/rooms/road15.c","south",
    "/players/softly/algiers/rooms/road10.c","north",
  });
}
