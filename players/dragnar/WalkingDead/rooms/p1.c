inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";
#include <ansi.h>

reset(arg) {
	string trees;
  if(arg) return;
  
  short_desc = "Path in King County "+HIG+"Forest"+NORM;
  trees = "The trees here are mostly evergreen pines that grow densely together\n\
and provide a feeling of restriction. Scattered in with the pines are\n\
some leafy trees like walnut and maple. The canopy from the trees here\n\
allows little "+HIY+"sunlight"+NORM+" in and somehow makes it difficult to breathe";
  set_light(1);
  items=({
    "path",
"Barely large enough for a man to pass through, it is dark and\n\
restricted with the forest so close. To the east the path seems\n\
to open up into a small clearing",
    "trees", trees,
    "undergrowth", 
"Many "+GRN+"ferns"+NORM+" with some nasty thorns compete for the little "+HIY+"sunlight"+NORM+"\n\
that is allowed in from the dense canopy",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in this part of the forest",
    "canopy", trees,
    "forest",
"The trees grow more and more dense further to the south. To the east\n\
is a break in the forest that looks like a small clearing. The forest\n\
continues south along the edge of the path as far as you can see.\n\
No traversable path in that direction can be seen",
    "ferns","The ferns are a "+GRN+"forest green"+NORM+" and are 10 inches tall",
    "thorns","The thorns are nasty, some 4 feet high with 3 inch prickers",
    "clearing", 
"You can see the "+HIY+"sunlight"+NORM+" is brighter there, but you can't make out\n\
any details from here"
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f3","northwest",
    "/players/dragnar/WalkingDead/rooms/p2","east",
  });
  long_desc=
"A narrow path runs through a dense forest here. The trees and\n\
undergrowth from the forest loom on both sides of the path. Travel\n\
is only possible on the path to the northwest or to the east where\n\
the path seems to open into a small clearing.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
