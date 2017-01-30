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
"The trees are fairly thick even close to the clearing, although it is\n\
passable. They block out much of the sunlight and make it quite gloomy.\n\
It is quiet in the forest, perhaps a bit too quiet",
    "trees",
"The trees dominate the forest.  Most are leafy trees such as cedar and\n\
chestnut, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches.  Up close you notice that many of the\n\
trees are covered in "+GRY+"moss"+NORM,
    "moss",
"Whatever type of moss this is, it doesn't seem to follow the standard\n\
of only growing on the north sides of the trees",
    "pavement","It is not possible to see details of the pavement from here",
    "clearing","A break in the trees can be seen to the west",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in this part of the forest",
    "leaves",
"Many shades of "+GRN+"green"+NORM+", the leaves gently sway in the breeze. They are\n\
beautiful, but they cause a sense of restriction.  Anything could be\n\
hiding in these trees with their leaves giving perfect cover",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f16","north",
    "/players/dragnar/WalkingDead/rooms/f1","south",
    "/players/dragnar/WalkingDead/rooms/f11","east",
    "/players/dragnar/WalkingDead/rooms/r2","west",
  });
  long_desc=
"The forest stretches out from this point in all directions.  The\n\
trees here are dense, but you can pass in all directions.  Farther to\n\
the south the forest seems to "+HIBLK+"darken"+NORM+". To the west the trees are\n\
cleared and a paved road runs north and south.  East heads deeper\n\
into the forest and seems to have a slight downhill slope.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
