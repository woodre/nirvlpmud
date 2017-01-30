#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("giant", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/gblack.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You have reached a faintly lit cave.  The only source of light is\n"+
"coming through a small opening in the west wall.  Dark shadows\n"+ 
"envelop the corners of the cave.  The brown walls give you a \n"+
"mysterious sense of danger, and the rocks look like thousands of \n"+
"faces staring at you silently.  The echo of your footsteps and heavy\n"+ 
"breathing catch your ears.\n";

items = ({
  "walls",
  "Brown rocky walls make you feel nervous",
  "cave",
  "You are standing in a faint lighted cave. Shadows are dancing\n"+
  "in the far corners",
  "rocks",
  "Dark brown rocks that looks like thousands of faces staring\n"+
  "silently at you",
  "faces",
  "They are only rocks!",
  "opening",
  "The light is coming through a small opening in the west wall",
  "shadows",
  "Dark shadows dances in the far corners of the cave",
  "corner",
  "You are blocking the light from reaching the corners",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/ma3.c","west",
});

}

	