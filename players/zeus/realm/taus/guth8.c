inherit "room/room";	/*  guth8.c  */
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
"The beautiful forest is very open here, the trees sparsely spaced.\n"+
"To the west the forest gets much thicker, and darker.  Numerous large\n"+
"holes have been dug out near the edge of the forest.  Lush grass is\n"+
"growing all around, scattered with colorful flowers.\n";
 set_light(1);
 items=({
	 "trees",
"The evergreen trees are growing very far apart, allowing the sun to\n"+
"shine down on the forest floor",
	 "forest",
"To the west the trees are growing very close together, making the forest\n"+
"much darker there",
	 "holes",
"The holes are a few feet wide and a couple deep, and have been dug near\n"+
"the edge of the forest",
	 "grass",
"The lush green grass is flourishing in this part of the forest",
	 "flowers",
"The lovely flowers are blooming in many different colors",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth6.c", "northwest",
	 "/players/zeus/realm/taus/guth7.c", "northeast",
	 "/players/zeus/realm/taus/guth11.c", "south",
 });
}


void init(){
	::init();
	add_action("s_dir", "south");
	add_action("nw_dir", "northwest");
	add_action("ne_dir", "northeast");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";    }