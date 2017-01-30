inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The forest is darker here, with a thicker canopy and fewer plants.\n"+
"A number of large trees have fallen, making travel to the south\n"+
"impossible from this point.  A large slab of stone rests upon the\n"+
"ground a little to the east of the defined path, covered in growth.\n";
  items=({
   "plants",
"Among the undergrowth are some beautiful plants, including some green\n"+
"bushes with dark blue blossoms which are hard not to gaze at",
   "ground",
"The ground is pretty bare here, highlighted by the occasional branch",
   "path",
"The path is for the most part bare here.  There are a few branches\n"+
"laying here and there, but it's mostly just dry brown dirt",
   "forest",
"The forest is rather dark here, thanks to the tall evergreen trees.\n"+
"Some pretty plants are growing off to the side of the path",
   "undergrowth",
"The undergrowth consists of some plain green ferns, some thick leafy\n"+
"bushes, and a lot of unidentifiable green plants",
   "branches",
"The branches of the trees are very full, and criss cross so that much\n"+
"of the sky is blocked from view.  Not much light is able to pass through",
   "trees",
"The evergreen trees are very tall, and have many branches.  A few trees\n"+
"have fallen to the south, making travel in that direction impossible",
   "slab", 
"The slab of stone looks peculiar, as it is perfectly flat on the\n"+
"ground, undisturbed by the growing trees and plants",
   "growth",
"The slab of stone is covered by moss and other small plants",
   "moss",
"There is green moss growing on the slab of stone",
   "stone",
"The slab of stone looks peculiar, as it is perfectly flat on the\n"+
"ground, undisturbed by the growing trees and plants",
   "canopy",
"The branches are creating a sort of canopy which is blocking most\n"+
"of the bright blue sky from view",
  });
  dest_dir=({
"/players/zeus/realm/city/path14.c", "north",
"/players/zeus/realm/city/path11.c", "east",
"/players/zeus/realm/city/ent.c", "west",
  });
}   }

  init(){
  ::init();
  add_action("w_dir", "west");
  add_action("e_dir", "east");
  add_action("n_dir", "north");
  add_action("move_cmd", "move");
  add_action("move_cmd", "pull");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

status move_cmd(string str){
 if(!str) return 0;
 if(str=="stone" || str=="slab" || str=="slab of stone"){
	write(
"You work your fingers under the slab and pull up as hard as you can...\n"+
"The slab of stone doesn't move an inch, it is far too heavy.\n");
	say(TP->QN+" pulls at the slab of stone.\n");
	}
return 1; }
