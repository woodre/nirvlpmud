inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"


reset(arg) {

  if(arg) return;
    
  short_desc = BGRN+BLK+"Black Creek Apartments"+NORM;
  set_light(1);
  items=({
    "couch","A black leather couch with oversized arms and wooden legs",
    "furniture","A dining room table and chairs and a bookcase fill out the room",
    "bookcase", "Most of the books are about guns and survival",
    "table", "A standard pine wood table with four matching chairs",
    "chairs", "Pine chairs with a fancy design carved in the back",
    "stairs", "The stairs head upstairs, if someone is around they must be there",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r8","west",
    "/players/dragnar/WalkingDead/rooms/t7","up",
  });
  long_desc=
"A fairly nice apartment at one point, it seems a bit bare at the\n\
moment. Modern appliances such as a TV and stereo have been removed\n\
making the apartment feel a bit sparse. Only the basics remain,\n\
including a couch and some other basic furniture. You can head west\n\
to exit the apartment or head upstairs via the stairs along the\n\
north wall.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}

