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
  A broad dirt road runs through the center of town. The normal\n\
bustle of everyday life is visible all around.  Northeast is\n\
a small red house. A church steeple is visible to the far west.\n\
East and west are small buildings built of concrete block.  The\n\
one to the east has a yellow brick facade and a large sign over\n\
the door.  The building to the west has a large window with racks\n\
of clothing visible. South a number of buildings look like the\n\
commercial center of Algiers.\n";

  items = ({
    "building", 
    "Behind a large window racks of clothing are visible",
    "facade",
    "The front of the small building is mortared with yellow brick",
    "sign",
    "Tom's Variety Store",
    "window",
    "A display window looks over the road.  Painted on the window\n\
is a sign that says 'Finest Clothing'",
    "racks",
    "Iron bars hold hanging clothes of all kinds",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple.",
    "life",
    "People and animals walk to and fro on the road",
    "road",
    "The brown earthen road is very dusty",
    "steeple",
    "A white steeple rises above a grey roof in the distance",
    "house",
    "A small wooden house painted dark red sits to the side\n\
of the road",
    "buildings",
    "A few wooden and concrete block buildings are visible",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/toms.c","east",
    "/players/softly/algiers/rooms/road10.c","south",
    "/players/softly/algiers/rooms/road6.c","north",
    "/players/softly/algiers/rooms/lvcshop.c","west",
  });
}
