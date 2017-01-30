inherit "room/room";	/*  guth5.c  */
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
"This is a somewhat secluded part of the forest.  The evergreen trees are\n"+
"growing very densely to the north east and south.  The sun can be seen\n"+
"high in the sky.  Above the tops of the trees to the northwest a large\n"+
"tower can be seen.  A small trail leads to the east.  Numerous holes\n"+
"are just barely visible in the tall green grass.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is quite dense to the north east and south",
	 "trees",
"The towering evergreen trees climb high into the sky",
	 "sun",
"The sun is shining high in the sky",
	 "tower",
"A large, circular shaped tower can be seen over the tops of the trees\n"+
"to the northwest",
	 "holes",
"The holes are hard to see because of the lush green grass.  Each one\n"+
"is a few feet wide and deep.  They are quite private",
	 "grass",
"The lush green grass grows abundantly all around",
	 "trail",
"A small trail is leading into the forest to the east.  It leads\n"+
"into darkness",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth4.c", "west",
 });
}


void init(){
	::init();
	add_action("w_dir", "west");
	add_action("e_dir2", "east");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }

e_dir2(){  
	write("You walk east along the trail...\n\n");
	if(e_dir()) return 1;
    TP->MP("east#/players/zeus/realm/taus/cave1.c");
	return 1;
}
