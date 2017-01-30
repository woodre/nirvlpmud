inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>
#include "../defs.h"

status search_flag;

reset(arg) {

 if(arg) {
    if( !present("oakley") )
      move_object(clone_object("/players/dragnar/WalkingDead/mons/oakley"), this_object());
    return;
  }
    
  short_desc = BGRN+BLK+"Black Creek Apartments"+NORM;
  set_light(1);
  items=({
    "window","A perfect sniper spot for the courtyard below",
    "mattress","A simple full sized mattress with a few tangled blankets on it",
    "blankets", "A plain brown wool and a red plaid one with holes",
    "guns", "Assorted rifles, shotguns, assault rifles, and pistols",
    "bows", "Both compound and cross bows with many arrows",
    "knifes", "There is everything from a folding pocket knife to a machete",
    "armor", "Assorted mis-matched gear from police and military gear",
    "furniture","The mattress is stained and lacking any kind of sheets",
    "floor","A wooden floor that has been badly gouged and scratched",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/t5","down",
  });
  long_desc=
"The upstairs of the apartment was once a loft, but it has been\n\
transformed into an armory. There is a single large window that\n\
overlooks the street below. The only furniture is a simple mattress\n\
lying on the floor. The rest of the room is a weapons stockpile.\n\
There are numerous guns, bows, knifes, and armor stacked here.\n\
Whoever stays here is well prepared to deal with any kind of threat.\n";
  
  if( !present("oakley") )
    move_object(clone_object("/players/dragnar/WalkingDead/mons/oakley"), this_object());
  
  reanimate_corpse();
}

init() {
	::init();
}


