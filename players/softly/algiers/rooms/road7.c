#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("stfolk")){ 
    move_object(clone_object("players/softly/algiers/mobs/folks.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Edge of Town";
  long_desc ="\n"+
    "  A small gravel covered path runs east and west on the\n\
edge of town, intersecting with a wide road to the east.  To\n\
the north a folding chair sits in front of a large sign.  To\n\
the southwest sits a white church with a tall steeple visible\n\
from a distance.  Townspeople move about easily, greeting each\n\
other and smiling.\n";


  items = ({
    "gravel",
    "Small irregular pieces of stone cover the road.  They\n\
are a dusty greyish blue color",
    "sign",
    "The back side of a sign is painted white.  It has no writing",
    "steeple", 
    "The square white steeple is topped by a grey asphalt roof",
    "path",
    "A path covered with blue-grey gravel intersects\n\
a dirt covered road",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple.",
    "road",
    "The brown earthen road is very dusty",
    "chair",
    "A worn wooden chair sits alone before the sign",
    "sigh",
    "Leaving the Town of Algiers - Come Back Soon",
    "church",
    "A white building with a steeple can be seen to the southwest",
    "townspeople",
    "Men, women, and children move comfortably about",

  });
  dest_dir = ({
    "/players/softly/algiers/rooms/road6.c","east",
    "/players/softly/algiers/rooms/road8.c","west",
  });
}
