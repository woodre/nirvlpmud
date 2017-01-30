inherit "room/room";
#include "/players/zeus/closed/fl_demon.h"
#include "/players/zeus/closed/all.h"

int teleport;

reset(arg){
 if(!arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;

  set_light(1);
  short_desc="The Fallen Lands";
  long_desc=
"The path is slightly crowded by the undergrowth here.  The dirt path\n"+
"continues into the forest to the north, and back to the southeast.\n"+
"There is a large rock sitting just off the path to the east.  To the\n"+
"southeast the forest opens up into a slight clearing.\n";
  items=({
   "path", 
"The path is quite dry here, the dirt is rocky and hard",
   "dirt",
"The brown dirty is dry and rocky",
   "rocks",
"There are many small rocks in the path.  They are all very dirty",
   "rock", 
"The large rock to the east of the path is about three feet wide and two\n"+
"feet tall.  There is moss growing on parts of it",
   "moss",
"Patched of green moss are growing on the rock",
   "trees", 
"The magnificent evergreen trees are very old and tall, each one competing\n"+
"with the others for what little light there is",
   "undergrowth", 
"The undergrowth is very beautiful here.  There are some multicolored\n"+
"plants that seem to be bursting with life",
   "plants",
"There are some very colorful plants here which seem almost magical",
   "forest", 
"The forest is dark here, and gets darker to the north.  The canopy of\n"+
"branches is doing a good job of blocking out the sky",
   "branches",
"The branches of the trees are blocking out the sky",
   "sky",
"The blue sky is hard to see through the trees",
   "clearing",
"There is a clearing in the forest to the southeast",
   "canopy",
"The branches of the evergreen trees are creating a thick canopy which\n"+
"blocks out most of the sky, making the area dark and forboding",
   "ground", 
"The ground is dry here.  It is quite rocky and fairly flat",
  });
  dest_dir=({
"/players/zeus/realm/taus/road1.c", "north",
"/players/zeus/realm/city/path19.c", "southeast",
  });
}  }

  init(){
  ::init();
  add_action("se_dir", "southeast");
  add_action("n_dir", "north");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm() { if(teleport) return "NT"; }
okay_follow(){ return 1; }

