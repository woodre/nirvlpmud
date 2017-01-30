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
  long_desc ="\n"+
    "  A broad dirt road runs through the center of town. The\n\
bustle of everyday life is visible all around.  Northeast is\n\
a small red house.  A church steeple is visible to the west.\n\
South a number of buildings look like the commercial center of\n\
Algiers.\n";

  items = ({
    "steeple", 
    "The square white steeple is topped by a grey asphalt roof",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple.",
    "life",
    "People and animals walk to and fro on the road",
    "road",
    "The brown earthen road is very dusty",
    "house",
    "A small wooden house painted dark red sits to the side\n\
of the road",
    "buildings",
    "A few wooden and concrete block buildings are visible",

  });
  dest_dir = ({
    "/players/softly/algiers/rooms/road7.c","west",
    "/players/softly/algiers/rooms/road9.c","south",
    "/players/softly/algiers/rooms/road5.c","north",
  });
}
