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
normal bustle of everyday life is visible all around.  A\n\
church steeple is visible to the far northwest.  Directly\n\
west is a small building that was converted from a house to\n\
a commercial establishment.  It is painted white and has a\n\
large awning covering the front door.  From the underside\n\
of the awning hang branches and roots.  A prominent sign is\n\
mounted beside the front door. North and south are a number\n\
of commercial buildings.\n";

  items = ({
    "door",
    "The open door is painted white to match the building",
    "supports",
    "Metal rods hold up the awning.  They have branches\n\
with leaves still attached hanging from them",
    "road",
    "The brown earthen road is very dusty",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple.",
    "life",
    "People and animals walk to and fro on the road",
    "steeple",
    "A white steeple rises in the distance",
    "building",
    "A small wooden house that has been converted to a shop\n\
sits to the side of the road.  It is well kept",
    "house",
    "The small one story house is covered in clapboard\n\
and painted white.  It has a bright red front door",
    "establishment",
    "A commercial shop, once a residence",
    "awning",
    "The white metal awning shades the front door",
    "branches",
    "Thin branches still laden with leaves hang\n\
from the sides of the awning",
    "roots",
    "Odd in appearance, several roots hang from\n\
string tied to the awning supports",
    "buildings",
    "A few wooden and concrete block buildings are visible",
"sign",
"A small white sign with black lettering that reads 'Herb Shop'",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road14.c","south",
    "/players/softly/algiers/rooms/road11.c","east",
    "/players/softly/algiers/rooms/road9.c","north",
    "/players/softly/algiers/rooms/hshop.c","west",
  });
}
