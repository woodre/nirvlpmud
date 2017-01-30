#include "/players/stark/defs.h"
inherit "/room/room.c";
int snake;
reset(arg) {
snake = 0;
  if (arg) return;
  set_light(1);
  short_desc="A dimly lit forest";
  long_desc=
"   Light pours down from the heavens above.  A slit in the green \n"+
"fabric of trees flows above the stream.  You stand on a log that \n"+
"connects two sides of a stream.  A worn path leads southward but is \n"+
"blocked by vines to the north.  The stream below pushes east, fighting \n"+
"and grinding away at the pebbles and sand.\n";

  items=({
"water",
"Rushing water creates a stream below",
"vines",
"Vines climb up the trees and droop down from their branches",
"light",
"Light and sky mirror the stream below",
"sky",
"Light and sky mirror the stream below",
"slit",
"A rip in the ever present forest ceiling",
"fabric",
"Ever present and light oppressive; the green fabric of the tree branches",
"stream",
"Water rushes down just below the log, you could 'hop' down into it",
"ceiling",
"The branches of the trees saturate the sky above",
"forest",
"A forest of thriving trees and other vegetation",
"trees",
"Strong trees rise high to a ceiling of branches",
"vegetation",
"Bushes, ferns and grasses carpet the floor",
"vines",
"Vines climb up the trees and droop down from their branches",
"carpet",
"The undergrowth is so lush that it creates a carpet of green",
"path",
"The log connects to a path north and south"
  });

  dest_dir=({
    "/players/stark/forest/forest2","south"
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("hop","hop");
}

search(str) {
 if(str == "vines" || str == "vine"){
  if(snake){
   write("You search the vines and and find nothing.\n");
   return 1;}
  write("You search the vines and find a snake!\n");
  move_object(clone_object("/players/stark/forest/mon/snake3.c"),this_object());
  snake = 1;
  return 1;}

  write("You search around and find you can 'hop' down to the stream below.\n");
  return 1;
}


hop(str) {
  write("You hop down to the stream below.\n");
  this_player()->move_player("into the forest#/players/stark/forest/forest4");
  return 1;
}
