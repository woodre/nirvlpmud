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
to take over. The forest continues west and south",
    "trees",
"Less dominating than further to the south, the trees here are fairly\n\
sparse. Most of the trees here are smaller leafy trees like sycamore\n\
and willow. The canopy here allows "+HIY+"sunlight"+NORM+" in and somehow makes\n\
it easier to breathe. Unfortunately the smell coming from the swamp\n\
does not necessarily make this a good thing",
    "moss",
"Whatever type of moss this is, it doesn't seem to follow the standard\n\
of only growing on the north sides of the trees",
    "leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
  "muck", "Brown mud that is perfect for growing cat-tails",
	"soil", "Brown mud that is perfect for growing cat-tails",
	"water", "The water in the swamp is mostly green due to "+GRN+"algae "+NORM+"growth",
    "swamp",
"The smell of decay is strong near the edge of the swamp. The edge\n\
is marked by the cat-tails that grow in the muck and thrive on the\n\
rich soil and abundant water. The swamp appears to be solid but\n\
anything that wanders in would most likely get stuck. There is no\n\
way a person could traverse the swamp",
    "buildings",
"The buildings seem to be no larger than three stories high, clearly\n\
this is not a large town. It is difficult to tell the exact purpose\n\
of the buildings from here, but they seem to be in good shape",
    "village",
"The village seems to be a pleasant small country village; at least\n\
it was at one point in the recent past. Now there is rubble strewn\n\
about, and a chain link fence surrounds the buildings. The fence\n\
prevents passage into the town, but perhaps the road to the west\n\
could provide a route into the town. It may however be safer to\n\
stay away",
    "fence",
"Eight feet tall with a roll of "+GRY+"barbed wire"+NORM+" at the top, it prevents\n\
entering the village from this point",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f17","south",
    "/players/dragnar/WalkingDead/rooms/f21","west",
  });
  long_desc=
"The forest thins out and ends at this spot. To the north the trees\n\
have been cleared and a small village is nestled on the top of the\n\
rise. To the west the forest continues and is easily traversed. On\n\
the east a "+YEL+"swamp"+NORM+" starts and stretches out as far as the eye can see.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}