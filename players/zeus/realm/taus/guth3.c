inherit "room/room";	/*  guth3.c  */
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
"The forest is very open here, allowing the sun to shine down on you.\n"+
"To the north a large stone tower is visible through the trees.  A small\n"+
"trail is leading through the forest to it.  To the south a large cluster\n"+
"of trees is growing.  Lush green grass coats the forest floor, scattered\n"+
"here and there by beautiful flowers.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is very open here, the trees growing very far apart from one\n"+
"another.  A cluster of trees is growing to the south, blocking travel",
	 "sun",
"The golden sun is shining down upon you",
	 "tower",
"The circular stone tower is built out of a grey stone and looks rather\n"+
"old.  In some places it has vines growing on it.  It towers high above\n"+
"the tops of the trees",
	 "vines",
"Some writhing green vines are clinging to the tower",
	 "grass",
"The soft green grass is growing all around",
	 "trees",
"The towering evergreen trees climb high into the sky",
	 "flowers",
"The colorful flowers dot the grassy fields, making it look very beautiful",
	 "cluster",
"The thick cluster of evergreen trees is blocking travel to the south",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/tower1.c", "north",
	 "/players/zeus/realm/taus/guth4.c", "east",
	 "/players/zeus/realm/taus/guth2.c", "west",
 });
}


void init(){
	::init();
	add_action("e_dir", "east");
	add_action("n_dir", "north");
	add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }
