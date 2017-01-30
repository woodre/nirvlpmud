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
"This is what appears to be a building, however it has no walls\n"+
"or ceiling, just a large pillar standing out of the ground, and\n"+
"another laying on the ground.  Plants and vines have consumed much\n"+
"of it over time.  To the southwest the forest is darker than here.\n";
  items=({
   "ground", 
"The ground consists of many pieces of broken stone from the building\n"+
"which once stood here.  Dirt and rocks are scattered all around.  There\n"+
"is a large pillar laying on the ground",
   "pillar",
"Please be more specific",
   "undergrowth", 
"There are many different types of plants here, making the undergrowth\n"+
"visually complex.  They are all tangeled amongst one another",
   "vines", 
"The vines are twisting around the other plants, and around the broken\n"+
"structure which you are standing in",
   "building", 
"It no longer can truthfully be called a building, but there is no doubt\n"+
"that some time ago it was one.  Pieces of stone are scattered along the\n"+
"ground, and two large pillars remain",
   "stone",
"There are many flat pieces of white stone on the ground.  Most of them\n"+
"are broken and cracked",
   "pieces",
"The pieces of stone are white, and most are broken and cracked",
   "pillars", 
"The pillars are faded and weigh a ton.  Each one is about a foot in\n"+
"diameter.  One of them is standing slightly crooked, the other is\n"+
"laying partially across the path",
   "plants", 
"The plants have grown over much of the structure over time.  There are\n"+
"many different types of plants growing here, many of which are entangled\n"+
"amongst one another",
   "forest", 
"The forest here is fairly open, allowing enough light to get to the\n"+
"forest floor for the undergrowth to thrive.  To the southwest the forest\n"+
"is darker than it is here",
   "canopy",
"The canopy of the forest is moderatly open here, allowing plenty of\n"+
"light to reach the plants below",
   "path",
"The path is made up of broken pieces of stone mixed with the dirt\n"+
"and rocks.  There are also some dead leaves here",
   "leaves",
"There are some dead brown leaves on the ground here.  They are very\n"+
"dry and crunch beneath your feat",
   "standing pillar",
"The pillar that is still standing is reaching about eight feet into\n"+
"the air, at which it has been broken off.  There is a very faded\n"+
"pattern painted onto the pillar, which has plants growing up around it",
   "fallen pillar",
"The pillar which is laying on the ground is very dirty and covered in\n"+
"plants and growth.  It is laying across the path, however it is easy\n"+
"to step over it",
  });
  dest_dir=({
"/players/zeus/realm/city/path15.c", "north",
"/players/zeus/realm/city/path6.c", "south",
"/players/zeus/realm/city/path10.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("n_dir", "north");
  add_action("s_dir", "south");
  add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm() { if(teleport) return "NT"; }
