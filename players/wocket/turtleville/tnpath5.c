#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"Turtleville"+NORM;
long_desc = ""+
"   Ahead to the north stands the grand City hall with its pillars and grand\n"+
"steps.  To the east lies the famed magus tower stretching high into the sky.\n"+
"Both seem caped with turtle shells roofs making shade to cool down the area\n"+
"from the warm day.  To the west leads back into town along the paved road.\n";

items = ({
  "stones","They are very smooth and have been walked on by many feet",
  "road","It is paved with very smooth stones",
  "city hall","It is a grand building with many pillars to the north",
  "tower","A tall cylindrical building that reaches for the sky",
  "magus tower","A tall cylindrical building that reaches for the sky",
  "hall","It is a grand building with many pillars to the north",
  "roofs","They seem to be made out of turtle shells",
  "pillars","They are dove white and look impressive holding up the City hall",
  "steps","Giant wide steps that lead up into the City hall",
});
  
smells = ({
   "default","It smells fresh and bright",
});

listens = ({
    "default","You hear the bustle of a bright day",
});
  
  dest_dir = ({
    PATH+"/tnpath3.c","west",
    PATH+"/tville_hall","north",
    PATH+"/tville_tower.c","east",
  });
set_light(1);
}
