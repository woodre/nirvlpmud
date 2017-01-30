#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("annie")){ 
    move_object(clone_object("players/softly/algiers/mobs/annie.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Front porch";
  long_desc ="\n"+
    "  The broad white porch covers the width of the house.\n\
A white railing surrounds it except for the space where a\n\
single step allows access to the road.  Small clay flower\n\
pots filled with greenery and flowers sit around the edges.\n\
Baskets of wool and silk surround a small rocking chair.\n";

  items = ({
    "porch", 
    "A porch the width of the house is surrounded with white\n\
railings.  Flowers sit in pots around the edges",
    "railing",
    "Painted white, a wooden railing surrounds the porch",
    "step",
    "The centered step is of grey weathered wood",
    "road",
    "road",
    "The brown earthen road is dusty",
    "pots",
    "Clay flower pots are filled with ferns and flowers",
    "greenery",
    "Luscious ferns overflow small flower pots",
    "flowers",
    "Small flowers dot the center of several flower pots",
    "edges",
    "The border of the porch under the railing\n\
has many flower pots sitting about",
    "baskets",
    "Huge hand-woven baskets are filled with black,\n\
brown, and white wool.  Brightly colored silks\n\
of many hues fill others",
    "wool",
    "Recently shorn, the wool is ready to be spun",
    "silk",
    "Fine threads of silk, dyed and ready to be spun,\n\
fill several baskets",

  });
  dest_dir = ({
    "/players/softly/algiers/rooms/road12.c","north",
  });
}
