inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	if(arg) return;
  
  short_desc = "Start of King County Route "+HIB+"19"+NORM;
  set_light(1);
  items=({
    "sign",
"Speed\n\
Limit\n\
"+HIBLK+" 55"+NORM,
    "road",
"A two lane country road with a "+HIY+"double line"+NORM+" running down the middle and\n\
"+GRY+"white lines"+NORM+" that mark the edges.  The paint is a bit faded, and the road\n\
has some small pot holes starting. It seems like the road hasn't been\n\
properly maintained recently",
    "forest",
"The trees are fairly thick even close to the road, although it is passable.\n\
They block out much of the sunlight and make it quite gloomy.  It is quiet\n\
in the forest, perhaps a bit too quiet",
    "trees",
"The trees dominate the forest.  Most are leafy trees such as oak and\n\
yellow-wood, but there are some evergreen pines as well. Many of the pines\n\
grow in "+GRN+"dark green"+NORM+" patches",
    "clearing","The area is void of any major growth for 5 feet on both sides\n\
of the road",
    "pot holes","Only a handful of small 1 inch holes in the pavement",
    "shoulder","A few inches of dirt in either side of the road",
    "dirt","The classic "+RED+"red clay"+NORM+" that you see in the southern states",
    "pines",GRN+"Darker "+NORM+"varieties of pine grow in that part of the forest",
    "flowers",
"These flowers are a group of Blue False Indigo.  They are around 2 feet\n\
high, with "+MAG+"dark indigo blue"+NORM+" clusters of flowers on long narrow stems.\n\
The leaves are "+GRN+"green"+NORM+" and petite, growing in groups of 5 around the stem",
    
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r2","north",
    "/players/dragnar/WalkingDead/rooms/entrance","south",
    "/players/dragnar/WalkingDead/rooms/f1","east",
    "/players/dragnar/WalkingDead/rooms/f4","west",
  });
  long_desc=
"The clearing from the south abruptly ends here and a country two\n\
lane road starts. On either side of the road a forest stretches off\n\
into the distance. The trees from the forest start not far from the\n\
edge of the shoulder of the road, and not much can been seen into the\n\
gloom.  There are a few "+MAG+"wild flowers"+NORM+" growing along the side of the road\n\
before the tree line. The road runs north and the way seems clear in \n\
that direction.  There is a traffic sign that you can just make out\n\
further along the road.\n";
  
  reanimate_corpse();
}

init() {
	::init();
}
