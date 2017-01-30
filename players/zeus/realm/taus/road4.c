inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, clone;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

	if(!present("guard")){   clone = random(3);   switch(clone){
	case 0: case 1:  break;
	case 2:  MO(CO("/players/zeus/realm/NPC/gguard.c"), TO); break;
	return 1; }}

  if(arg) return;
  short_desc="The Fallen Lands";
  long_desc=
"You have reached a simple wooden bridge in the forest.  The river is\n"+
"flowing quickly beneath the bridge, about ten feet below.  The forest\n"+
"is very thick all around the river, however plenty of light is still\n"+
"breaking through the canopy of branches above.\n";
  set_light(1);
  items=({
	   "bridge",
"The wooden bridge is simply four large trees which have been placed\n"+
"over the river.  The trees, which have been stripped clean of their\n"+
"branches, are tied together by thick green vines",
	   "forest",
"The forest is very thick around the river.  The trees are growing just\n"+
"feet from the edge of the water",
	   "river",
"The river is about ten feet below the bridge.  It looks to be only about\n"+
"five feet wide at this point, and it is flowing very fast.  Some white\n"+
"rocks can be seen poking out of the water",
	   "water",
"The water is flowing quickly, crashing against the rocks in the river",
	   "rocks",
"Some smoothed off white rocks can be seen jutting out of the river",
	   "branches",
"The branches of the tall evergreen trees fan out across the sky",
	   "trees",
"The forest consists mostly of towering evergreen trees.  Their branches\n"+
"fan out across the sky, blocking much of it out",
       "sky",
"The blue sky is difficult to see through the branches of the trees",
	   "canopy",
"The branches of the trees create a virtual canopy above",
	   "light",
"Rays of light can be seen piercing through the canopy of branches above",
  });
  dest_dir=({
	  "/players/zeus/realm/taus/guth12.c", "north",
	  "/players/zeus/realm/taus/road3.c", "south",
  });
}

  void init(){
	::init();
  add_action("n_dir", "n");
  add_action("n_dir2", "n");
  add_action("s_dir", "s");
}


exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }

status n_dir2()
{
	if(present("guard"))
	{
		write("The guard watches you closely.\n");
		say("The guard watches "+TP->QN+" closely.\n");
	}
}