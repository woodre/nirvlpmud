/*   Gurther Taus 9  */

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
"The forest is very open and alive in this area.  The trees are very\n"+
"sparse, allowing the beautiful sun to shine down on the forest floor.\n"+
"To the west is a small cluster of shady oak trees.  In every direction\n"+
"the forest continues to be open and bright.\n";
 set_light(1);
 items=({
	 "forest",
"The trees are growing very far apart around here, making the forest seem\n"+
"very open and warm.  It is a very pleasant environment",
     "trees",
"Most of the trees are towering evergreen trees, which looks as though\n"+
"they have been growing here for centuries.  There is a cluster of oak\n"+
"trees growing to the west.  A small trail leads to the west into the\n"+
"cluster of oak trees",
     "sun",
"The bright yellow sun is shining down on the clearing",
     "floor",
"The floor of the forest is grassy, and in many places patches of grass\n"+
"have been worn away",
     "grass",
"Lush green grass is growing all around.  In some places though it isn't\n"+
"growing very well because creatures walk on it so often",
     "patches",
"There are some patches where grass is no longer growing",
     "cluster",
"To the west is a shady cluster of oak trees.  It looks like a very\n"+
"tranquil place to rest and relax.  A small trail is leading to the\n"+
"west, into the cluster",
     "trail",
"A trail is visible leading into the cluster of oak trees to the west",
     "oak trees",
"There is a cluster of oak trees to the west.  They are quite tall,\n"+
"and are creating a lot of shade beneath them.  A small trail is\n"+
"leading into the cluster to the west",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth10.c", "east",
	 "/players/zeus/realm/taus/guth12.c", "southwest",
	 "/players/zeus/realm/taus/grove.c", "west",
	 "/players/zeus/realm/taus/guth7.c", "northwest",
 });
}


void init(){
	::init();
	add_action("nw_dir", "northwest");
	add_action("e_dir", "east");
	add_action("sw_dir", "wouthwest");
	add_action("w_dir", "west");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }

realm(){   if(teleport) return "NT";    }
