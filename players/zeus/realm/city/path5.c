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
"The path appears to end here.  To the east there is a slight drop off\n"+
"into a fast flowing river.  The bank of the other side of the river can\n"+
"be seen about 15 feet across.  All the trees and plants growing here\n"+
"are growing very fully, making it hard to see anything beyond the\n"+
"path to the north or south.\n";
  items=({
   "trees", 
"There a lot of trees to the south, however not as many to the north\n"+
"of the path, which is mostly blocked by large ferns and bushes",
   "canopy", 
"The trees aren't creating much of a canopy here.  As a result, the\n"+
"plants are growing very well and it is easy to see here",
   "path", 
"The path is very muddy here because everything is so wet.  The path\n"+
"drops right off into the river, which is only a few feet to the east",
   "undergrowth", 
"The undergrowth is alive with variety here, cosisting of some beautiful\n"+
"ferns and bushes.  There are also some lovely flowers to the south",
   "river", 
"The river is flowing extremely quickly to the north.  Some rough\n"+
"looking rocks are sticking out of the water",
   "rocks",
"There are a number of rough looking rocks protruding from the river",
   "bank", 
"The bank of the river is at least 15 feet away.  It is a lined with\n"+
"rocks and trees, and there is no clear way to get onto the shore",
   "riverbank", 
"The riverbank is at least 15 feet away.  It is basically a wall of\n"+
"rocks and trees at this point",
   "plants", 
"There are some very healthy bushes and ferns growing here, as well\n"+
"as some pretty flowers growing just to the south of the path",
  });
  dest_dir=({
"/players/zeus/realm/city/path4.c", "west",
  });
}  }

  init(){
  ::init();
  add_action("north_dir", "north");
  add_action("w_dir", "west");
  add_action("n_dir", "north");
  add_action("listen_cmd", "listen");
  add_action("search_cmd", "search");
}

realm(){   if(teleport) return "NT"; }
okay_follow(){ return 1; }

status north_dir(){
 write("You part the undergrowth and walk north.\n");
 TP->MP("north#/players/zeus/realm/city/path9.c");
return 1; }

status listen_cmd(){
	write("The rushing waters of the river are all that can be heard.\n");
	say(TP->QN+" listens carefully.\n");
return 1; }

status search_cmd(){
 write("You search the room carefully and discover a less used path hidden\n"+
          "by the undergrowth to the north.\n");
 say(TP->QN+" searches around.\n");
return 1; }
