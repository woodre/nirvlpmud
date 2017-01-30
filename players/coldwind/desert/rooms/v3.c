#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("giant", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/gred.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    Your feet have led you into the ruins of a small village. It \n"+
"seems like the village was under a malicious attack lately.  Tens of\n"+
"tents had been burned, while a few others have been destroyed under the \n"+
"palm tree which had fallen down.  Some palm trees are still standing \n"+
"tall allowing the shade to spread over the area.  A small pond can be\n"+
"seen to the northwest, yet the fallen trees block you from proceeding\n"+
"that way.\n";

items = ({
  "palms",
  "Deep red palms hanging toward the top of the palm trees",
  "houses",
  "Burned and destroyed tents extend north and west",
  "tents",
  "Burned and destroyed tents extend north and west",
  "ruins",
  "A few palm trees had fallen over some tents, while tens of other\n"+
  "tents were burned or destroyed cruely",
  "pond",
  "A small pond is beaming back at the face of the sun to the northwest",
  "sun",
  "The palm trees are blocking the sunlight..",
  "sunlight",
  "The palm trees are blocking the sunlight..",
  "palm trees",
  "They stand around 30 feet tall, growing deep red palms, while others have\n"+
  "fallen over some of the tents",
  "fallen trees",
  "A few palm trees had fallen over some tents destroying them and blocking you\n"+
  "from walking east and northwest",
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v6.c","north",
  "/players/coldwind/desert/rooms/v2.c","west",
});

}


	