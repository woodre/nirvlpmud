#include "/players/softly/closed/define.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("octave")){ 
    move_object(clone_object("players/softly/algiers/mobs/octave.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Front yard";
  long_desc ="\n"+
    "  A small yard with patches of grass covering some of the\n\
earth sits between a road and a small wooden house painted dark\n\
red.  Two windows peek out from under canvas awnings and a few\n\
multicolored flowers surround the slightly ajar white front door.\n\
On close inspection a tiny sign on the door is visible.\n";

  items = ({
    "yard",
    "A patch of earth with a bit of grass",
    "earth",
    "Brown hard packed dirt",
    "grass",
    "Scruffy tan and green grass grows in irregular shapes",
    "windows",
    "The small windows, covered with screens, are hidden by awnings",
    "house",
    "A small wooden house painted dark red sits to the east.",
    "awnings",
    "Threadbare tan canvas awnings with a single red stripe\n\
cover the two front windows of the house.",
    "road",
    "The brown earthen road runs north and south through\n\
the town of Algiers.  It is very dusty",
    "flowers",
    "Huge red and white hibiscus grow on dark green shrubs.\n\
A few blue and pink phlox sit at their feet",
    "sign",
    ""+HIY+"  @"+HIG+"`-"+HIR+"  Readings"+HIG+"  -,"+HIY+"@"+NORM+"",
    "door",
    "The slightly ajar door has a small sign afixed",
  });
  dest_dir = ({
    "/players/softly/algiers/rooms/road5.c","west",
    "/players/softly/algiers/rooms/rhouse.c","enter",
  });
}
