inherit "room/room";	/*  guth7.c  */
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
"All around the sun is shining down upon the forest floor.  Lush green\n"+
"grass is growing heartily.  Everything is very beautiful here.  The\n"+
"forest gets signifigantly thicker to the east.  A few large holes have\n"+
"been dug out near the edge of the denser forest.  Some beautiful flowers\n"+
"are growing here and there.\n";
 set_light(1);
 items=({
	 "sun",
"High above the golden sun is shining down upon the entire area",
	 "grass",
"The lush green grass is flourishing here, it coats the forest floor",
	 "forest",
"Around you the forest is very open, with only an occasionaly tree.\n"+
"To the east the trees get much thicker",
	 "holes",
"A few large, somewhat deep holes have been dug out near the edge\n"+
"of the denser forest to the east",
	 "flowers",
"The delicate flowers are yellow and red.  They look perfect",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth4.c", "north",
	 "/players/zeus/realm/taus/guth9.c", "southeast",
	 "/players/zeus/realm/taus/guth8.c", "southwest",
 });
}

void init(){
	::init();
	add_action("n_dir", "north");
	add_action("sw_dir", "southwest");
	add_action("se_dir", "southeast");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow() { return 1; }
realm(){   if(teleport) return "NT";    }