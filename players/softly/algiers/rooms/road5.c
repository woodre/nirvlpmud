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
    "  A broad dirt road runs through the center of a small town.\n\
A weathered white wooden sign sits off of the road to the west.\n\
North the road narrows and turns out of sight.  A bright small\n\
house sits behind a small yard to the east.  The road continues\n\
to the south where more buildings are visible.\n";


  items = ({
    "steeple", 
    "The square white steeple is topped by a grey asphalt roof",
    "yard", 
    "Unlike its surroundings, the yard has a few small trees\n\
and bounteous flowers",
    "earth", 
    "The brown earth is packed hard",
    "buildings",
    "A few wooden and concrete block buildings are visible",
    "house",
    "A small wooden house painted dark red sits to the side\n\
of the road",
    "sign",
    "Algiers, pop. 621",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple",
    "road",
    "The brown earthen road is very dusty",

  });
  dest_dir = ({
    "/players/softly/algiers/rooms/yard.c","east",
    "/players/softly/algiers/rooms/road4.c","north",
    "/players/softly/algiers/rooms/road6.c","south",
  });
}
