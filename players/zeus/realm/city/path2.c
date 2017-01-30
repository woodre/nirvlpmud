inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"This is a very well defined path.  It is used frequently by the\n"+
"creatures which reside in these woods.  To the south an ancient\n"+
"structure can be slightly seen through the trees.  To the north\n"+
"the forest opens up into a sort of clearing.  A less used path\n"+
"leads to the west into a darker part of the forest.\n";
  items=({
   "structure", 
"The remains of the structure are in ruins, torn apart by the weather."+
"\nThe forest has consumed them and it is impossible to reach them",
   "forest",
"To the west the forest gets thicker and darker",
   "path",
"The rocky path is well defined here because it is used so often",
   "trees",
"The thick trees are very tall and have many branches, which makes it\n"+
"quite difficult to see the structure to the south",
   "woods",
"The ancient trees are all around you.  To the west the light seems\n"+
"to disappear because the forest is so thick",
   "clearing",
"To the north the path opens into a clearing.  It is lighter there, as\n",
"though it is calling you to go there",
  });
  dest_dir=({
"/players/zeus/realm/city/path6.c", "north",
"/players/zeus/realm/city/path3.c", "east",
"/players/zeus/realm/city/path1.c", "west",
  });
} }

  init(){
  ::init();
  add_action("w_dir", "west");
  add_action("e_dir", "east");
  add_action("n_dir", "north");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }
