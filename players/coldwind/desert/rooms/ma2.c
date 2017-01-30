#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("fares", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/fares.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    A large rocky cave shields you from the direct sunlight and the \n"+
"sandy wind.  The brown walls give you a mysterious sense of danger, \n"+
"while the rocks look like thousands of faces staring at you silently.\n"+
"You can see a small opening in the east wall leading outside.  The \n"+
"echo of your footsteps and heavy breathing catch your ears.\n";

items = ({
  "walls",
  "Brown rocky walls with many cracks in them",
  "cave",
  "Sand have accumulated over the years on the rocky floor. You notice\n"+
  "many cracks in the brown walls",
  "sand",
  "Yellow soft sand covers the floor partially",
  "floor",
  "The rocky ground is partially covered by sand",
  "cracks",
  "It seems like someone was banging on the walls with a heavy tool",
  "rocks",
  "Dark brown rocks that look like thousands of faces staring silently at you",
  "faces",
  "They are only rocks!",
  "opening",
  "The light is coming through a small opening in the east wall",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/ma1.c","east",
});

}

	