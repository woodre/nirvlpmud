inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "King County "+HIG+"Forest"+NORM;
  set_light(1);
  items=({
   "ferns","The ferns are a "+GRN+"forest green"+NORM+" and are 10 inches tall",
   "cat-tails",
"Around 8 feet tall, they have a flowering spike on the end of their\n\
tall stems.  They are growing in a large clump on the edge of the\n\
swamp.  They are so thick they make it almost impossible to get a good\n\
view of what is in the swamp beyond",
   "forest",
"The trees grow more and more sparse closer to the edge of the swamp.\n\
Near the "+YEL+"swamp"+NORM+" the trees are dwarfed and the "+GRN+"ferns and cat-tails"+NORM+" start\n\
to take over. The forest continues north and south along the swamp\n\
edge and west back toward the road",
    "trees",
"Less dominating than further to the west, the trees here are fairly\n\
sparse. Most of the trees here are smaller leafy trees like walnut\n\
and buck-thorn. The canopy here allows "+HIY+"sunlight"+NORM+" in and somehow makes\n\
it easier to breathe. Unfortunately the smell coming from the swamp\n\
does not necessarily make this a good thing",
    "leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
    "canopy","The canopy is mostly made up of "+GRN+"leaves"+NORM+" high overhead",
	"road", "The road is not visibile through the trees from this point",
	"muck", "Brown mud that is perfect for growing cat-tails",
	"soil", "Brown mud that is perfect for growing cat-tails",
	"water", "The water in the swamp is mostly green due to "+GRN+"algae "+NORM+"growth",
	"swamp",
"The smell of decay is strong near the edge of the swamp. The edge\n\
is marked by the cat-tails that grow in the muck and thrive on the\n\
rich soil and abundant water. The swamp appears to be solid but\n\
anything that wanders in would most likely get stuck. There is no\n\
way a person could traverse the swamp",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f18","north",
    "/players/dragnar/WalkingDead/rooms/f3","south",
    "/players/dragnar/WalkingDead/rooms/f11","west",
  });
  long_desc=
"The forest thins out here and the slope comes to an end at a "+YEL+"swamp"+NORM+"\n\
that stretches to the east.  The swamp has no visible path through it.\n\
The forest continues north and south along the edge of the swamp and\n\
also back toward the road to the west.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}