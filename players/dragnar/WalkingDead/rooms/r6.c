inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

reset(arg) {
  string warehouse;
  
  if( !present("guard") ) 
    move_object(clone_object("/players/dragnar/WalkingDead/mons/guard"), this_object());
  
	if(arg) return;
  
  short_desc = BGRN+BLK+"Black Creek - Main ST"+NORM;
  set_light(1);
  warehouse = "The largest building in the village, it is a 3 story building that has seen\n\
better days. The east side of the building facing the road has an\n\
entrance, but it has boarded up and cannot be entered";
  items=({
    "road",
"A two lane village road with a "+HIY+"double line"+NORM+" running down the middle and\n\
"+GRY+"white lines"+NORM+" that mark the edges.  The paint is a bit faded, and the road\n\
has some small pot holes starting. It seems like the road hasn't been\n\
properly maintained recently.",
    "warehouse", warehouse,
    "building", warehouse,
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "barbed wire","Razor wire with 3 inch barbs that change directions",
    "alley", "A short alley that runs between the buildings and ends with a fence",
    "fence", "Eight feet tall with a roll of "+GRY+"barbed wire"+NORM+" at the top, it prevents\n\
Walkers from wandering into the village",
    
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r7","north",
    "/players/dragnar/WalkingDead/rooms/r5","south",
    "/players/dragnar/WalkingDead/rooms/t2","east",
  });
  long_desc=
"The main road of Black Creek runs north and south from this point.\n\
To the east is an alley that ends at the fence. To the west is a\n\
large warehouse, but there is no immediate way to enter it.\n";
  
}

init() {
	::init();
}
