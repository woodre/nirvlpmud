inherit "room/room";	/*  guth1.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, clone;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

	if(!present("gurther")){   clone = random(6);   switch(clone){
	case 0: case 1: case 2: case 3: case 4: break;
	case 5:  MO(CO("/players/zeus/realm/NPC/gurther.c"), TO); break;
	return 1; }}
 if(arg) return;

 short_desc="The Fallen Lands";
 long_desc=
"You are standing in a somewhat seculded part of the forest.  The towering\n"+
"evergreen trees are growing fairly densely to the north, south and west.\n"+
"There is a natural spring here, which is filling a small pool with crystal\n"+
"clear water.  Lush green grass is growing all around, and the sun can be\n"+
"seen through the trees above.\n";
 set_light(1);
 items=({
	 "forest",
"The forest is quite dense to the north west and south, making travel in\n"+
"any of those directions extremely difficult",
	 "trees",
"The towering evergreen trees climb high into the sky",
	 "spring",
"A natural spring is flowing up from the ground and filling a small pool\n"+
"with water.  The water is coming right out of the ground",
	 "pool",
"The pool is maybe four or five feet deep and ten or eleven in diameter.\n"+
"The water is perfectly clear, and actually looks rather warm",
	 "water",
"The clear water looks somewhat warm.  It is coming from the natural spring\n"+
"in the ground",
	 "grass",
"All around the pool lush green grass is growing",
	 "sun",
"Through the trees above the sun can be seen glowing brightly",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/guth2.c", "east",
 });
}

void init(){
	::init();
	add_action("e_dir", "east");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow() { return 1; }