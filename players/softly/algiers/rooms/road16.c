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
  A small dirt road narrows as it moves northeast.  To\n\
the west it intersects with a broad dirt road.  Beyond\n\
is a small white commercial structure.  To the north is\n\
the side of a blue streaked building.  The road continues\n\
both northeast and west.\n";

  items = ({
    "sign",
    "The lettering on the sign is too small to read from here",
    "window",
    "Gold lettering on the window is too difficult to\n\
read at this distance",
    "road",
    "The brown earthen roads are very dusty",
    "structure",
    "A small white building with a large window is\n\
across the main road",
    "building",
    "The blue streaked building seems as if it had been\n\
dipped in water when the paint was still wet.  There is\n\
a sign above the white front door",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road15.c","west",
    "/players/softly/algiers/rooms/road17.c","northeast",
  });
}
