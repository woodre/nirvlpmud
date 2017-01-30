#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You can hear your heart beating as loud as a drum in the silent\n"+
"area.  You are standing before the ruins of a small village. Tens of\n"+
"tents have been burned or destroyed.   A few palm trees have fallen \n"+
"over some of the tents, while other trees stand tall allowing the\n"+
"shade to spread over the area.  Footprints of different sizes mark\n"+
"the sandy ground.  A small pond can be seen to the north.  The \n"+
"destroyed village houses extend northeast and further east.\n";

items = ({
  "palms",
  "Deep red palms hanging toward the top of the palm trees",
  "houses",
  "Burned and destroyed tents extend northeast and further east",
  "tents",
  "Burned and destroyed tents extend northeast and further east",
  "ruins",
  "A few palm trees had fallen over some tents, while other tents had\n"+
  "cruely burned or destroyed",
  "pond",
  "A small pond is beaming back at the face of the sun to the north",
  "sun",
  "The palm trees are blocking the sunlight..",
  "sunlight",
  "The palm trees are blocking the sunlight..",
  "palm trees",
  "They stand around 30 feet tall, carrying deep red palms, while others have\n"+
  "fallen over some of the tents",
  "fallen trees",
  "A few palm trees have fallen over some tents destroying them and blocking you\n"+
  "from walking northeast and northwest, and leaving a very narrow opening to\n"+
  "proceed north",
  "opening",
  "The fallen trees formed a very narrow opening for those who wish to proceed\n"+
  "north",
  "footprints",
  "Footprints of different races. Some are recent",
  "ground",
  "You notice some recent footprints mark the sandy ground",
  "sand",
  "The soft yellow sand covers the area",
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v5.c","north",
  "/players/coldwind/desert/rooms/v1.c","west",
  "/players/coldwind/desert/rooms/v3.c","east",
});

}


	