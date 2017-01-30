#include "/players/stark/defs.h"
inherit "/room/room.c";
int snake;
reset(arg) {
snake = 0;
  if (arg) return;
  set_light(1);
  short_desc="A dimly lit forest";
  long_desc=
"   The forest becomes darker from here on in. The trees are now larger \n"+
"and older.  Jungle vines grow up and wrap around the trees.  Vegetation \n"+
"grows abundantly across the forest floor.  There is a worn path going \n"+
"eastward.\n";

  items=({
"forest",
"A forest of thriving trees and other vegetation",
"trees",
"Strong trees rise high to a ceiling of branches",
"vines",
"Vines climb up the trees and droop down from their branches",
"vegetation",
"Bushes, ferns and grasses carpet the floor",
"path",
"A path leads through the jungle to the east" 
  });

  dest_dir=({
    "/room/south/sforst17","west"
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("east","east");
}

search(str) {
 if(str == "vines" || str == "vine"){
  if(snake){
   write("You search the vines and and find nothing.\n");
   return 1;}
  write("You search the vines and find a snake!\n");
  move_object(clone_object("/players/stark/forest/mon/snake1.c"),this_object());
  snake = 1;
  return 1;}
 write("You search briefly and find a path to the east.\n");
 return 1;}

east() {
  write("You walk down the path through a forest.\n");
  this_player()->move_player("into the forest#/players/stark/forest/forest2");
  return 1;
}
