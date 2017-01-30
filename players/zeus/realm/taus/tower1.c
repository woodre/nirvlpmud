inherit "room/room";	/*  tower1.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, clone;
object guard;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

	if(!present("gurther")){ 
	guard = CO("/players/zeus/realm/NPC/gguard2.c");
	guard->set_wc(36);  guard->set_hp(600);  MO(guard, TO);  }

  if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"You are standing before a large tower.  The circular tower is made of a\n"+
"dull grey stone and climbs high into the sky.  Evergreen trees are growing\n"+
"all around the tower, crowding up around it.  Some thorny bushes are\n"+
"growing around the tower amongst the trees.  The sun can be seen overhead.\n";
 set_light(1);
 items=({
	 "tower",
"The circular tower looms high in the sky.  It is made of a dull grey stone\n"+
"and towers above the evergreen trees next to it.  A large archway sits at\n"+
"the front of the tower, gaping open as if inviting you to 'enter' it",
	 "stone",
"Each block of the grey stone is a few feet wide, and looks incredibly heavy",
	 "archway",
"The large archway leads into the tower.  One could 'enter' it",
	 "trees",
"The mighty evergreen trees grow all around the tower, but none reach as\n"+
"high into the sky",
	 "bushes",
"Some vicious looking thorny bushes are growing amongst the trees,\n"+
"preventing any movement through the trees",
	 "sun",
"The golden sun is visible in the sky.  It is shining brightly",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth3.c", "south",
 });
}


void init(){
	::init();
	add_action("enter_cmd", "enter");
	add_action("s_dir", "south");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

status enter_cmd(string str){
	if(!str) return 0;
	if(str == "archway" || str == "tower"){
		if(present("guard")){
			write("The guard blocks your path.\n");
			return 1;
		}
		write("You enter the tower...\n");
		TP->MP("into the tower#/players/zeus/realm/taus/tower2.c");
		return 1;
	}
	else return 0;
	return 1;
}