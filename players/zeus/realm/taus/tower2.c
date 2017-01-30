inherit "room/room";	/*  tower2.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){	

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

  if(arg) return;
 short_desc="Auseth's Tower";
 long_desc=
"You are standing inside the main entrance of the tower.  This is a fairly\n"+
"open room, with numerous paintings hanging on the walls.  There is a small\n"+
"door on the east wall, and a large staircase that bends upwards to the\n"+
"second floor.  A large red carpet is spread out across the floor.\n";
 set_light(1);
 items=({
	 "paintings",
"There are numerous paintings hanging on the bland grey walls of the tower.\n"+
"Most of them are portraits of humans wearing long robes, however a few\n"+
"depict horrible battle scences.  They are all beautifully done",
	 "door",
"It is a simple oak door with three iron strips running along it",
	 "staircase",
"The staircase is very large, and curves up the western wall to the floor\n"+
"above.  It is constructed from the same grey stones which the entire tower\n"+
"is built from",
	 "carpet",
"An extremely large red carpet has been spread out over the main floor.\n"+
"It is rather thick and extremely well woven.  A pattern of black swirls\n"+
"runs through the center of it",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/tower1.c", "out",
	 "/players/zeus/realm/taus/tower3.c", "east",
	 "/players/zeus/realm/taus/tower4.c", "up",
 });
}


void init(){
	::init();
	add_action("e_dir", "east");
	add_action("e_dir2", "east");
	add_action("u_dir2", "up");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

e_dir2(){	write("You enter the east room...\n\n");   }
u_dir2(){   write("You walk up the stairs...\n\n");   }
