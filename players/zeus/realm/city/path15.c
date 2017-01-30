inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){
 if(!arg){

  teleport = 0;  if(random(2)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path leading through the forest here is very defined.  To the\n"+
"east a structure can be seen through the trees, engrossed in vines\n"+
"and weeds.  The trees tower high above the path, fighting for what\n"+
"little light there is.  The path is strewn with twigs and leaves.\n";
  items=({
   "trees", 
"The thick evergreen trees tower high into the sky, their branches criss\n"+
"crossing, creating a canopy which blocks out much of the sky",
   "sky",
"Only patches of the beautiful blue sky can be seen through the canopy\n"+
"of the evergreen trees branches",
   "forest", 
"The beautiful evergreen trees climb high into the sky, their branches\n"+
"creating a thick canopy which blocks out pieces of the sky",
   "weeds",
"There are some small, feisty little weeds growing out of the structure\n"+
"to the east",
   "undergrowth",
"The undergrowth here isn't terribly thick, probably due to the limited\n"+
"natural light.  The forest beyond the path is still very thick however",
   "canopy",
"The canopy of branches is blocking out a good portion of the sky, however\n"+
"enough light is still reaching the forest floor to allow the plants to grow",
   "path", 
"It would seem as though something has been walking through here.  The\n"+
"leaves on the path have been pushed into the dirt",
   "leaves",
"There are brown and yellow leaves scattered across the path, many of\n"+
"which have been pressed into the dirt",
   "dirt",
"The path is fairly dry here, and is covered in leaves and twigs",
   "twigs", 
"There are some dirt laden brown twigs scattered over the path.  Many\n"+
"of them are broken because they've been stepped on",
   "structure", 
"The ancient structure is made from white stone, however very little of\n"+
"the stone can still be seen because of the forest",
   "vines", 
"The vines are dark green and fairly thick.  They, along with the rest\n"+
"of the forest have nearly consumed the old fragmented structure",
  });
  dest_dir=({
"/players/zeus/realm/city/path19.c", "north",
"/players/zeus/realm/city/path11.c", "south",
"/players/zeus/realm/city/path14.c", "west",
  });
}   }

  init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }

