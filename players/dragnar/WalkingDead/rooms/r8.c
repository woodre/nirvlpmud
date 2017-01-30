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
    "apartment", 
"A building that was cut into separate apartments with 4 or 5 units\n\
in it. There are wooden spears surrounding the building and some\n\
kind of barbed wire between the spears. It looks like someone\n\
wanted to prevent walkers from entering the building. Ironically\n\
a newer Welcome mat is placed perfectly in front of the door",
    "spears", "Shaved wooden sticks with the ends carved into a sharp point",
    "sticks", "Wooden shafts made from hard maple trees",
    "flesh", "Impossible to tell what left these chunks behind",
    "building","A small two story apartment building",
    "village","This village seems to be pretty secure compared to the\n\
surrounding forest area",
    "wire", "Some of the barbs still have "+HIBLK+"chunks of blackened flesh"+NORM+" stuck to them",
    "mat", "The Welcome mat just seems so out of place, maybe it would be best\n\
to step over it rather than just heading east into the building",
    "fence", "Eight feet tall with a roll of "+GRY+"barbed wire"+NORM+" at the top, it prevents\n\
Walkers from wandering into the village",
    
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r7","south",
    "/players/dragnar/WalkingDead/rooms/t6","east",
  });
  long_desc=
"The main road that runs down the village is cut off at this point\n\
by the large fence that encircles the town. The fence cuts off the\n\
directions north and west. To the east is a two story apartment\n\
building, and the road is clear to the south.\n";
  
  reanimate_corpse();
}

init() {
	::init();
  add_action("Step","step");
}

Step(string str ) {

  if( !str )
    return 0;
  
  if( str == "over mat" || str == "over welcome mat" ) {
    this_player()->move_player("east#/players/dragnar/WalkingDead/rooms/t5");
    return 1;
  } 
}
