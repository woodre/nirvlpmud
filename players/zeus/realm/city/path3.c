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
"This is a very well defined path through the forest.  To the south\n"+
"the forest is very thick and impenetrable, however glimpses of fallen\n"+
"structures can be seen.  The trees create a canopy above, blocking\n"+
"out a good portion of the light\n";
  items=({
   "structures", 
"The ancient ruins have fallen and lay in waste, consumed by the forest",
   "leaves",
"Some leaves are laying on the path that have a bright red pattern on\n"+
"them.  Some of them have very faded colors",
   "forest",
"The forest is very thick here.  The trees are mostly evergreens,\n"+
"however there are a number of other types of trees as well",
   "trees", 
"The ancient trees reach high into the sky.  Their branches crisscross\n"+
"over the path creating a canopy which blocks out much of the light",
   "path",
"The path is well defined here because it is used so often by the\n"+
"creatures who live here.  There are leaves and rocks scattered across\n"+
"it haphazardly",
   "rocks",
"Many small rocks are scattered across the path haphazardly",
   "canopy",
"The canopy the branches of the trees create blocks most of the sky\n"+
"from view.  Very little light is able to penetrate through",
   "sky",
"The light blue sky can barely be seen through the canopy created by\n"+
"the branches of the trees",
   "plants",
"There are some very colorful plants growing here in abundance.  One\n"+
"in particular has a bright red pattern on it's leaves",
   "undergrowth",
"The plants here are alive with variety and color.  A plant with red\n"+
"leaves seems to grow in abundance here",
  });
  dest_dir=({
"/players/zeus/realm/city/path7.c", "north",
"/players/zeus/realm/city/path4.c", "east",
"/players/zeus/realm/city/path2.c", "west",
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
realm(){   if(teleport) return "NT"; }
