inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

reset(arg) {
  
	if(arg) return;
  
  short_desc = BGRN+BLK+"Black Creek - Main ST"+NORM;
  set_light(1);

  items=({
    "road",
"A two lane village road with a "+HIY+"double line"+NORM+" running down the middle and\n\
"+GRY+"white lines"+NORM+" that mark the edges.  The paint is a bit faded, and the road\n\
has some small pot holes starting. It seems like the road hasn't been\n\
properly maintained recently.",
    "pub", 
"A small, local, towny bar, not the finest establishment ever made, but\n\
probably good enough to throw back a few drinks and forget the world\n\
has gone to hell",
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "pharmacy", 
"Another mom and pop joint, it looks like it would at least have the\n\
basics of medications, if it hasn't been looted.",
    
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r8","north",
    "/players/dragnar/WalkingDead/rooms/r6","south",
    "/players/dragnar/WalkingDead/rooms/t4","east",
    "/players/dragnar/WalkingDead/rooms/t3","west",
  });
  long_desc=
"The main road of Black Creek runs north and south from this point.\n\
To the west is a building that looks to be a pub, and on the east\n\
side of the road is an entrance to a pharmacy.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
