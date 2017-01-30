#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = ""+
"   The smooth stones pave the way through the city.  The road comes to a\n"+
"tee here, while south leads back through town, west leads to the\n"+
"turtleville marsh.  The city hall is just in sight to the east, along with\n"+
"the famous magus tower.\n";

items = ({
  "stones","They are very smooth and have been walked on by many feet",
  "road","It is paved with very smooth stones",
  "city hall","It is a grand building with many pillars in the east",
  "tower","A tall cylidrical building in the distance",
  "magus tower","A tall cylidrical building in the distance",
  "city","The city of Turtleville, filled with many houses and shops",
  "marsh","Weeping trees with pale leaves and tall grass make up the marsh",
});
  
smells = ({
   "default","It smells fresh and bright",
});

listens = ({
    "default","You hear the bustle of a bright day",
});
  
  dest_dir = ({
    PATH+"/tnpath4.c","west",
    PATH+"/tnpath2.c","south",
    PATH+"/tnpath5.c","east",
  });
set_light(1);
}
