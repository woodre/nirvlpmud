inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "King County "+HIG+"Forest"+NORM;
  set_light(1);
  items=({
    "road",
"Glimpses of pavement can be seen through the trees, but you can't see\n\
much detail through the leaves",
    "forest",
"The forest ends here at the edge of the village. The trees are\n\
sparse compared to further south, but they still provide ample cover\n\
for things to hide from sight",
    "trees",
"The trees dominate the forest.  Most are leafy trees such as cedar and\n\
chestnut, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches.  Up close you notice that many of the\n\
trees are covered in "+YEL+"moss"+NORM,
    "moss",
"Whatever type of moss this is, it doesn't seem to follow the standard\n\
of only growing on the north sides of the trees",
    "leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
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
    "pavement","The pavement is just starting to show signs of neglect",
	"pines",GRN+"Darker "+NORM+"varieties of pine grow in this part of the forest",
	"fence",
"Eight feet tall with a roll of "+GRY+"barbed wire"+NORM+" at the top, it prevents\n\
entering the village from this point",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f16","south",
    "/players/dragnar/WalkingDead/rooms/f22","east",
    "/players/dragnar/WalkingDead/rooms/r4","west",
  });
  long_desc=
"The forest stretches out from this point to the south and east. To\n\
the north the forest ends and a small village is nestled on the top\n\
of the rise. The trees here are thinning out as the forest reaches\n\
the border of the village. To the west the trees are cleared and a\n\
paved road runs north and south. East heads deeper into the forest\n\
and seems to have a slight downhill slope.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
