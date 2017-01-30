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
  The narrow dusty dirt road passes the sides of several\n\
shops.  To he north is a yellow brick wall and to the\n\
south a wooden wall of blue streaked with rose, white,\n\
and yellow.  West a wider road can be seen with a small\n\
white building hugging the road.  The small road continues\n\
to the east.\n";

  items = ({
    "road",
    "The narrow road intersects a wider road to the west",
    "shops",
    "Several shops are nearby.  They front onto\n\
the westward road",
    "wall",
    "The side of Tom's Variety is yellow brick.\n\
The side of Belle's Parlor is painted many colors",
    "building",
    "Barely visible, a white bulding with an awning\n\
sits by the side of a wider road to the west",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road12.c","east",
    "/players/softly/algiers/rooms/road10.c","west",
  });
}
