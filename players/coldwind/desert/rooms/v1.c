#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("villager", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());        
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());        
	}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    A few palm trees have developed here, blocking the sunlight somewhat\n"+
"and allowing the shade to grow around.  Footprints of different sizes\n"+
"mark the sandy ground.  A beautiful pond can be seen to the northeast,\n"+
"while what looks like small tents start to the east.\n";

items = ({
  "palms",
  "Deep red palms hanging toward the top of the palm trees",
  "tents",
  "Hrmm...you will need to get closer to get a better look",
  "pond",
  "A small pond is beaming back at the face of the sun to the northeast",
  "sun",
  "The palm trees are blocking the sunlight...",
  "sunlight",
  "The palm trees are blocking the sunlight...",
  "palm trees",
  "They stand around 30 feet tall, carrying deep red palms",
  "footprints",
  "Footprints of different races mark the sand. Some are very recent",
  "ground",
  "You notice some recent footprints mark the sand",
  "sand",
  "The soft yellow sand covers the area",
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v4.c","north",
  "/players/coldwind/desert/rooms/v5.c","northeast",
  "/players/coldwind/desert/rooms/v2.c","east",
});

}