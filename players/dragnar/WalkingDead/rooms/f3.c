inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "King County "+HIG+"Forest"+NORM;
    set_light(1);
  items=({
   "ferns","The ferns are a "+GRN+"forest green"+NORM+" and are 10 inches tall",
   "cattails",
"Around 8 feet tall, they have a flowering spike on the end of their\n\
tall stems.  They are growing in a large clump on the edge of the\n\
swamp.  They are so thick they make it almost impossible to get a good\n\
view of what is in the swamp beyond",
   "forest",
"The trees grow more and more sparse closer to the edge of the swamp.\n\
Near the "+YEL+"swamp"+NORM+" the trees are dwarfed and the "+GRN+"ferns and cat-tails"+NORM+" start\n\
to take over.  Between the edge of the swamp and the more dense forest\n\
to the south you can see a very narrow path that runs southeast. The\n\
forest continues north along the swamp edge and west back toward the\n\
road. South the forest becomes dense and no path in that direction\n\
can be seen",
    "trees",
"Less dominating than further to the west and south, the trees here\n\
are fairly sparse. Most of the trees here are smaller leafy trees\n\
like walnut and buck-thorn. The canopy here allows "+HIY+"sunlight"+NORM+" in and\n\
somehow makes it easier to breath. Unfortunately the smell coming\n\
from the swamp does not necessarily make this a good thing",
    "leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
  "muck", "Brown mud that is perfect for growing cat-tails",
	"soil", "Brown mud that is perfect for growing cat-tails",
  "road", "The road is not visible from this point",
	"water", "The water in the swamp is mostly green due to "+GRN+"algae "+NORM+"growth",
    "swamp",
"The smell of decay is strong near the edge of the swamp.  The edge\n\
is marked by the cat tails that grow in the muck and thrive on the\n\
rich soil and abundant water. The swamp appears to be solid but\n\
anything that wanders in would most likely get stuck. There is no\n\
way a person could traverse the swamp",
    "path",
"Probably a game trail, it is just wide enough for a person to pass\n\
southeast between the swamp and the dense forest. It is not possible\n\
to see where the path leads",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f12","north",
    "/players/dragnar/WalkingDead/rooms/f2","west",
  });
  long_desc=
"The forest thins out here and the slope comes to an end at a "+YEL+"swamp"+NORM+"\n\
that stretches to the east.  The swamp has no visible path through it.\n\
The forest continues north along the edge of the swamp and back toward\n\
the road to the west. South the forest dominates and the trees grow\n\
too dense to pass easily through it.\n";
  
  reanimate_corpse();
}

init() {
	::init();
  add_action("SouthEast","se");
  add_action("SouthEast","southeast");
}

SouthEast() {
  this_player()->move_player("southeast#/players/dragnar/WalkingDead/rooms/p1");
  return 1;
}