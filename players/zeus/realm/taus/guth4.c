inherit "room/room";	/*  guth4.c  */
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
"All around you the forest is quite open.  Looking north the forest begins\n"+
"to get much darker and denser.  A small trail is leading to the east, and\n"+
"the main open part of the forest continues to the south.  The sun can be\n"+
"seen high in the sky, beaming down on the entire forest.  Over the trees\n"+
"to the northwest a grey tower can be seen.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is very open, allowing the sun to beam down on you\n"+
"To the north the forest gets much darker and denser",
	 "sun",
"The beautiful golden sun is glowing high in the sky",
	 "grass",
"Lush green grass is growing all around",
	 "trail",
"A smaller trail is leading into the forest to the east",
	 "trees",
"Mighty evergreen trees reaching high into the sky",
	 "tower",
"A large, circular shaped tower can be seen over the tops of the trees\n"+
"to the northwest",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth5.c", "east",
	 "/players/zeus/realm/taus/guth7.c", "south",
	 "/players/zeus/realm/taus/guth3.c", "west",
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