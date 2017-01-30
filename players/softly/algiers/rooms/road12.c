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
  The narrow dirt road passes a small soft green house\n\
with a broad white porch to the south.  An occasional\n\
small tree grows by the side of the road.  To the west\n\
several buildings of many colors can be seen.  The road\n\
continues west and turns to the north.\n";

  items = ({
    "road",
    "The brown earthen road is very dusty",
    "house",
    "A wooden clapboard house painted soft green.  It\n\
has a white porch the width of the house and white\n\
matching shutters aside the windows",
    "tree",
    "A small magnolia and several maples grow beside the road",
    "buildings",
    "Small buildings dot the sides of the road to the west.\n\
They are yellow, blue, and white.  A town seems nearby",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road13.c","north",
    "/players/softly/algiers/rooms/road11.c","west",
    "/players/softly/algiers/rooms/porch.c","south",
  });
}
