inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "King County "+HIG+"Forest"+NORM;
  set_light(1);
  items=({
   "ferns","The ferns are a "+GRN+"forest green"+NORM+" and are 10 inches tall",
   "forest",
"The trees grow more and more sparse closer to the edge of the village.\n\
Near the fence line the trees have been cleared and the moss and ferns\n\
start to take over. The forest continues west and south",
    "trees",
"Less dominating than further to the south, the trees here are fairly\n\
sparse. Most of the trees here are smaller leafy trees like sycamore\n\
and willow. The canopy here allows "+HIY+"sunlight"+NORM+" in and somehow makes\n\
it easier to breath. Unfortunately the smell coming from the swamp\n\
does not necessarily make this a good thing",
    "moss",
"Whatever type of moss this is, it doesn't seem to follow the standard\n\
of only growing on the north sides of the trees",
    "canopy","The canopy is mostly made up of "+GRN+"leaves"+NORM+" high overhead",
	"rubble","Items that once had value are now useless junk",
	"leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
    "buildings",
"The buildings seem to be no larger than three stories high, clearly\n\
this is not a large town. It is difficult to tell the exact purpose\n\
of the buildings from here, but they seem to be in good shape",
    "cliff",
"The cliff is not exactly vertical, but it would be almost impossible\n\
to traverse down it safely. Ferns and other ground cover grow on the\n\
rock face wherever they can find a crack, and occasionally small\n\
trees will even take root.",
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
    "/players/dragnar/WalkingDead/rooms/f14","south",
    "/players/dragnar/WalkingDead/rooms/f20","east",
  });
  long_desc=
"The forest thins out and ends at this spot. To the north the trees\n\
have been cleared and a small village is nestled on the top of the\n\
rise. To the east the forest continues and is easily traversed. On\n\
the west a sharp cliff face starts and runs down below. The cliff is\n\
not vertical, but it cannot be climbed safely.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}