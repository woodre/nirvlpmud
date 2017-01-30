#include "/players/stark/defs.h"
inherit "/room/room.c";
int snake;
reset(arg) {
snake = 0;
  if(!present("drand")) {
   move_object(clone_object("/players/stark/forest/mon/drand.c"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A dimly lit forest";
  long_desc=
"   Only thin streams of light can cut through the forest ceiling.  \n"+
"Trees push high into the air with lush branches of green.  Vines wrap \n"+
"around the trunks and droop down from the branches.  Ferns, bushes and \n"+
"wild grasses carpet the ground.  Husks of formerly mighty trees now \n"+
"nourish moss and small plants.  One former giant is suspended over a \n"+
"rushing stream.\n";

  items=({
"light",
"Light breaks forth from small breaks in the ceiling",
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
"husks",
"Trees long dead and fallen over",
"moss",
"Slick and soft grass clings to the trees",
"tree",
"One fallen tree bridges a stream to the north",
"stream",
"Rushing water flows through a stream, an old tree has fallen over it"

  });

  dest_dir=({
    "/players/stark/forest/forest1","west"
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
}

search(str) {
 if(str == "vines" || str == "vine"){
  if(snake){
   write("You search the vines and and find nothing.\n");
   return 1;}
  write("You search the vines and find a snake!\n");
  move_object(clone_object("/players/stark/forest/mon/snake2.c"),this_object());
  snake = 1;
  return 1;}
 write("You search briefly and find a path to the north.\n");
 return 1;}

north() {
  write("You walk down the path through a forest.\n");
  this_player()->move_player("into the forest#/players/stark/forest/forest3");
  return 1;
}
