inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "King County "+HIG+"Forest"+NORM;
  set_light(1);
  items=({
    "forest",
"The trees are fairly dense here, and create a "+GRN+"green canopy"+NORM+" overhead.\n\
The "+GRN+"leaves"+NORM+" block out much of the sunlight and make it quite gloomy.\n\
It is quiet in the forest, perhaps a bit too quiet",
    "trees",
"The trees dominate the forest.  Most are leafy trees such as yew and\n\
redwood, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches. Up close you notice that many of the\n\
trees are covered in "+YEL+"moss"+NORM,
    "canopy","The canopy is mostly made up of "+GRN+"leaves"+NORM+" high overhead",
	"pines",GRN+"Darker "+NORM+"varieties of pine grow in this part of the forest",
	"moss",
"Whatever type of moss this is, it doesn't seem to follow the standard\n\
of only growing on the north sides of the trees",
    "leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f19","north",
    "/players/dragnar/WalkingDead/rooms/f8","south",
    "/players/dragnar/WalkingDead/rooms/f15","east",
    "/players/dragnar/WalkingDead/rooms/f13","west",
  });
  long_desc=
"The forest stretches out from this point in all directions. The\n\
trees here are dense, however the route is clear enough for passage.\n\
The forest rises slightly to the west, and to the east a sharper\n\
downhill grade leads further down into the forest.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
