inherit "room/room";	/*  guth2.c  */
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
"The forest is very open here, allowing the sun to shine down upon the\n"+
"entire area.  Lush green grass is growing abundantly.  A hollow log is\n"+
"resting among the grass, half covered by weeds.  A few holes have been\n"+
"dug out around the edge of the forest.  A large, circular shaped stone\n"+
"tower is visible through the trees to the northeast.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is very open here, the trees growing very far apart from one\n"+
"another.  To the west the forest gets much thicker and darker",
	 "trees",
"The towering evergreen trees climb high into the sky",
	 "sun",
"The sun is shining down on the entire forest, feeding it with life",
	 "grass",
"The lush green grass is very soft.  It is all rather short, only a\n"+
"few inches tall in any one place",
	 "log",
"The hollow log is sitting amongst the grass, half covered in weeds.\n"+
"Bending over, you are able to see straight through it",
	 "weeds",
"A few resillant weeds are growing on the hollow log",
	 "holes",
"A few wide holes, a few feet deep have been dug out near the edge of the\n"+
"thick trees to the north",
	 "tower",
"The top of a large grey stone tower are visible to the northeast",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth3.c", "east",
	 "/players/zeus/realm/taus/guth6.c", "south",
	 "/players/zeus/realm/taus/guth1.c", "west",
 });
}


void init(){
	::init();
	add_action("e_dir", "east");
	add_action("s_dir", "south");
	add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";    }