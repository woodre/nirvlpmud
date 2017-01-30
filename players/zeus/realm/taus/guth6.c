/* 12/06/05 Earwax: converted to land for purchase by Z
 *   Permission given by Zeus
 */
inherit "room/room";	/*  guth6.c  */
#include "/players/zeus/closed/all.h"
inherit "/players/earwax/housing/land";
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
"The forest is very open here, although to the west it gets much darker\n"+
"and thicker.  There is a rather hard to see trail which leads into the\n"+
"forest to the west.  Lush green grass is growing all around, scattered\n"+
"with colorful flowers.  To the east a cluster of evergreen trees is\n"+
"growing.  The sun can be seen overhead, shining down upon the forest.\n";
 set_light(1);
 items=({
   "trail",
"The rather dark and subtle trail leads into the forest to the west",
	 "forest",
"You are standing in a very open part of the forest, the trees that remain\n"+
"are growing very far apart.  To the west the forest is much darker however",
	 "grass",
"The lush green grass is growing very well here",
	 "flowers",
"The colorful flowers look beautiful, scattered all across the forest floor",
	 "cluster",
"The thick cluster of trees stands tall in the middle of the open area",
	 "trees",
"A thick cluster of evergreen trees have grown in the middle of this\n"+
"open area to the east",
	 "sun",
"The golden sun is directly above you, feeding the forest with energy",	
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth2.c", "north",
	 "/players/zeus/realm/taus/guth8.c", "southeast",
     "/players/zeus/realm/x/path1.c", "west",
 });
  set_realm_name("Fallen Lands");
  set_lot_size(-2);
  set_cost(800000);
  setup_land();
}


void init(){
	::init();
	add_action("n_dir", "north");
    add_action("w_dir", "west");
	add_action("se_dir", "southeast");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";    }
