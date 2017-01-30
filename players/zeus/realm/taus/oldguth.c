/*  oldguth.c   - contains old gurther who barters */

inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){

 teleport = 0;  if(random(TFL_TLP)) teleport = 1;
 if(!present("gurther")) MO(CO("/players/zeus/realm/NPC/g-old.c"), TO); 

 if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"You are standing in a small clearing just past where the denser forest\n"+
"begins.  There are leaves scattered all over the ground, as well as two\n"+
"very large holes.  A small path is leading back into the open forest to\n"+
"the east.  The towering trees are blocking out most of the light.\n";
 set_light(1);
 items=({
	 "forest",
"The forest consists mostly of evergreen trees.  There branches span out\n"+
"over you, blocking out most of the light",
	 "leaves",
"The floor of the forest is scattered with dead leaves here, most of which\n"+
"are shades of yellow and green.  It looks very beautiful",
	 "ground",
"The ground is scatted with dead leaves",
	 "holes",
"There are two large holes in the ground, on the western edge of the small\n"+
"clearing.  Each one is a about four feet wide and a few feet deep.  They\n"+
"are lined with leaves",
	 "path",
"A small path leads out of the small clearing to the open forest to the east",
	 "trees",
"The powerful evergreen trees reach high into the sky, their branches\n"+
"fanning out above you, blocking out most of the light",
	 "branches",
"The branches of the evergreen trees seem to reach out over the forest,\n"+
"blocking out most of the light",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth11.c", "east",
 });
}


void init(){
	::init();
	add_action("e_dir", "east");
}

realm(){   if(teleport) return "NT";    }
exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }