inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

reset(arg) {
  string lot;
  
  if( !present("guard") ) {
    move_object(clone_object("/players/dragnar/WalkingDead/mons/guard"), this_object());
    move_object(clone_object("/players/dragnar/WalkingDead/mons/guard"), this_object());
  }
	if(arg) return;
  
  short_desc = BGRN+BLK+"Black Creek - Main ST"+NORM;
  set_light(1);
  lot = "Fairly large for a small town, but even from here it looks like\n\
it is in need of some repairs";
  items=({
    "road",
"A two lane village road with a "+HIY+"double line"+NORM+" running down the middle and\n\
"+GRY+"white lines"+NORM+" that mark the edges.  The paint is a bit faded, and the road\n\
has some small pot holes starting. It seems like the road hasn't been\n\
properly maintained recently. A barricade has been constructed near\n\
the edge of the village line",
    "barricade",
"Two older pickups have been placed end to end to block passage of any\n\
vehicles into the village. It doesn't seem the best way to keep out\n\
Walkers, so maybe this is to keep people out",
     "store",
"A small, one story, mom and pop sporting goods store. The original\n\
sign has been spray painted over to read: "+BGRN+BLK+"Black Creek"+NORM+" Survival Shop",
    "building", "A small sporting goods store",
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "sign",BGRN+BLK+"Black Creek"+NORM+" Survival Shop",
    "pickups","A Silverado and an F150",
    "silverado","The first generation from 1999 and looks very rough",
    "f150","Looks like a model from the early 90's. It doesn't look like it\n\
would run so it must have been pushed into place by someone",
    "lot", lot,
    "parking lot", lot,
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r6","north",
    "/players/dragnar/WalkingDead/rooms/r4","south",
    "/players/dragnar/WalkingDead/rooms/shop","east",
    "/players/dragnar/WalkingDead/rooms/t1","west",
  });
  long_desc=
"The main road of Black Creek runs north and south from this point.\n\
To the east is a smaller building that looks like a sporting goods\n\
store. On the west side of the road is a parking lot and the road\n\
continues south past the town barricade.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
