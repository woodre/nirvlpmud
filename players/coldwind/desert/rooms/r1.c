#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("carpet", this_object())){
move_object(clone_object("/players/coldwind/desert/items/carpet.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"   You stand on a well used path surrounded by an endless desert.  \n"+
"The sky is blue and clear and the sun makes the sand awfully hot \n"+
"under your feet.  A few cactus plants are growing on both sides of the\n"+
"path giving you an uneasy feeling. \n";

items = ({
  "path",
  "The constant travel through this area made the sand more\n"+
  "dense, forming a sandy path that leads south and east",
  "desert",
  "Yellow sand cover the ground and dunes as far as the eye can see",
  "sky",
  "It's blue and clear of any clouds",
  "sun",
  "The orange glowing sphere is floating in the heart of the sky",
  "sand",
  "The soft golden particles cover the endless desert",
  "cactus",
  "The green plants are covered with small sharp thorns. They are growing\n"+
  "on both sides of the path like skeleton hands reaching for help",
  "plants",
  "The green plants are covered with small sharp thorns. They are growing\n"+
  "on both sides of the path like skeleton hands reaching for help",
  "sides",
  "A few cactus plants are growing on both sides of the path",
  "dunes",
  "Distant sandy hills decorates the endless desert",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/r2.c","east",
});

}

	