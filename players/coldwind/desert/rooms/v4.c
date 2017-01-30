#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("ape", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/apes.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/apes.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You stand at the entrance to a village.  A sign has been placed\n"+
"here to welcome the visitors and merchants.  A well used path starts \n"+
"here leading somewhere deep in the desert of Dahna.  Palm trees tower\n"+
"high shielding you from the sunrays.  You notice a small pond to the \n"+
"east and some knocked down palm trees blocking you from proceeding\n"+
"northeast.\n";

items = ({
  "entrance",
  "A welcoming sign has been posted here and the village can be seen\n"+
  "in the far east",
  "village",
  "Small houses can be seen in the far east",
  "houses",
  "They seem too small from here to see any details...",
  "sign",
  "A wooden sign was placed here.\n"+
  "It reads: "+BOLD+" Welcome To Al' Ben El'Mansour"+NORM+"",
  "path",
  "A well used sandy path starts here and proceeds west toward\n"+
  "the infinite desert",
  "sun",
  "The palm trees are blocking the sunlight...",
  "sunrays",
  "The palm trees are blocking the sunlight...",
  "palm trees",
  "They stand around 30 feet tall, while others have been knocked down",
  "fallen trees",
  "Few palm trees have been knocked down detroying some tents and\n"+
  "blocking you from walking northeast",
  "pond",
  "To the east, you can see a crystal blue pond reflecting the\n"+
  "sunlight playfully", 
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v1.c","south",
  "/players/coldwind/desert/rooms/v5.c","east",
   "/players/coldwind/desert/rooms/r4.c","west", 
});
}

	