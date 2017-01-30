inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, clone, guth;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

	if(!present("gurther")){   clone = random(5);   switch(clone){
	case 0: case 1: case 2: break;
	case 3:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
	case 4: for(guth = 0; guth < 2; guth++)
			MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
	return 1; }}

  if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"This is an open part of the forest.  To the southwest the forest is much\n"+
"thicker and darker.  The sun can be seen shining brightly in the sky.\n"+
"The ground has been worn down in many places from all the traffic.  There\n"+
"are some large holes in the ground, especially near the edge of the dense\n"+
"forest.  A small trail is leading into the forest to the west.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is very open here, allowing much sunlight to reach the forest\n"+
"floor.  To the southwest the forest gets much darker and denser",
     "sun",
"The sun is lighting up the entire area, making is radiate with life",
     "sky",
"The soft blue sky is beautiful, dotted by faint white clounds",
     "clouds",
"A few soft white whisps of clouds are floating through the sky",
     "ground",
"Lush green grass is growing across much of the ground, however in many\n"+
"places the grass has been worn away and only dirt remains.  There are\n"+
"numerous large holes in the ground, especially near the denser forest",
     "holes",
"The holes have been dug into the ground.  Most of them are about three to\n"+
"six feet around and about 3 feet deep.  Some of them are much larger\n"+
"though",
     "trees",
"The forest consists mostly of towering evergreen trees which block out\n"+
"all of the light.  Around here the trees are very sparse, and the area\n"+
"breathes with life",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth8.c", "north",
	 "/players/zeus/realm/taus/guth12.c", "east",
	 "/players/zeus/realm/taus/oldguth.c", "west",
 });
}


void init(){
	::init();
	add_action("n_dir", "north");
	add_action("e_dir", "east");
	add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }
