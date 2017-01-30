inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "King County Route "+HIB+"19"+NORM;
  set_light(1);
  items=({
  "sign",
BGRN+BLK+"Village of Black Creek"+NORM,
    "road",
"A two lane country road with a "+HIY+"double line"+NORM+" running down the middle and\n\
"+GRY+"white lines"+NORM+" that mark the edges.  The paint is a bit faded, and the road\n\
has some small pot holes starting. It seems like the road hasn't been\n\
properly maintained recently. A barricade has been constructed near\n\
the edge of the village line",
    "forest",
"The trees thin out here as the forest approaches the village line.\n\
It is possible to travel to both the east and west into the forest.\n\
To the south the trees become more dense and the forest "+HIBLK+"darkens"+NORM,
    "trees",
"The trees dominate the forest.  Most are leafy trees such as ash and\n\
cherry, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches",
    "barricade",
"Two older pickups have been placed end to end to block passage of any\n\
vehicles into the village. You might be able to go north to bypass the\n\
barricade. However, spray painted on the side of the trucks is the\n\
message: "+HIR+"'TURN BACK! OVERRUN WITH BITERS, KEEP OUT'"+NORM,
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in that part of the forest",
    "rubble","Items that once had value are now useless junk",
    "buildings","From here it is not possible to tell what they are used for",
    "pickups","A Silverado and an F150",
    "silverado","The first generation from 1999 and looks very rough",
    "f150","Looks like a model from the early 90's. It doesn't look like it\n\
would run so it must have been pushed into place by someone",
"The buildings seem to be no larger than three stories high, clearly\n\
this is not a large town. It is difficult to tell the exact purpose\n\
of the buildings from here, but they seem to be in good shape",
   "village",
"The village seems to be a pleasant small country village; at least\n\
it was at one point in the recent past. Now there is rubble strewn\n\
about, and the barricades do not bode a pleasant welcome. If there\n\
are people here, they are nervous and most likely trigger happy\n\
toward strangers",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r3","south",
    "/players/dragnar/WalkingDead/rooms/f21","east",
    "/players/dragnar/WalkingDead/rooms/f20","west",
  });
  long_desc=
"A road runs directly north and south here. To the north the tops of\n\
small buildings can be seen that must make up a country village.\n\
There is a sign on the side of the road that marks the edge of the\n\
village. Just before the sign, a barricade has been constructed to\n\
block passage from the road into the village. The forest dominates\n\
the east and west sides of the road, and the road continues to the\n\
south clear of any obstructions.\n";
  
  reanimate_corpse();
}

init() {
	::init();
  add_action("North","n");
  add_action("North","north");
}

North() {
  this_player()->move_player("north#/players/dragnar/WalkingDead/rooms/r5");
  return 1;
}