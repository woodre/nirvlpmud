#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The only source of light is coming through a small opening in \n"+
"the west wall.  Dark shadows dance in the far the corners of the cave.  \n"+
"The brown walls give you a strange feeling of danger and fear, and \n"+
"the rocks look like thousands of faces staring at you silently.  The\n"+
"air is very thick here forcing you to do some effort to breathe. \n"+ 
"The echo of your footsteps and heavy breathing reach your ears.\n";

items = ({
  "walls",
  "Brown rocky walls make you feel nervous",
  "cave",
  "You are standing in a faint lighted cave. Shadows are dancing in the far corners",
  "rocks",
  "Like thousands of faces staring silently at you",
  "faces",
  "They are only rocks!",
  "opening",
  "The light is coming through a small opening in the west wall",
  "shadows",
  "Dark shadows dances in the far corners of the cave",
  "corners",
  "You are blocking the light from reaching the corners",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/ma5.c","west",
});

}


	