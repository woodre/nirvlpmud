inherit "room/room";	/*  tower4.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

  if(arg) return;
 short_desc="Auseth's Tower";
 long_desc=
"This is the second floor of the tower.  You are in what appears to be\n"+
"a sort of library.  There are numerous bookshelves along the walls, as\n"+
"well as a couple chairs and a large wooden table.  A small door on the\n"+
"east wall is leading into another room, and the main staircase continues\n"+
"up to the third floor of the tower.  There are a few windows in the walls\n"+
"of the tower that are allowing some light into the dim tower.\n";
 set_light(1);
 items=({
	"bookshelves",
"There are numerous bookshelves in the room, each made of a strong oak.\n"+
"Every one is completely filled with books, texts and scrolls that all\n"+
"look very old",
	"books",
"There are many books lining the bookshelves in the room.  Most of them\n"+
"are in rather poor shape, and are not bound very well.  They contain\n"+
"untold amounts of knowledge",
	"texts",
"There are numerous texts lining the bookshelves in the room.   Each is\n"+
"filled with untold centuries of knowledge",
	"scrolls",
"There are numerous scrolls on the bookshelves in the room.  Some of them\n"+
"are in such poor condition that they are about to crumble to pieces",
	"chairs",
"A few fine oak chairs are sitting around an oak table in the center of\n"+
"the room.  They are in good condition, and do not look very comfortable",
	"table",
"The large oak table looks very sturdy and well made.  It is rectangular\n"+
"and has a few oak chairs around it.  A couple scrolls have been left\n"+
"out on the table",
	"door",
"It is a plain oak door that leads into a side room",
	"staircase",
"The wide stone staircase curves up along the west wall to the third\n"+
"floor of the tower",
	"windows",
"The simple windows provide a nice view of the forest below.  The window\n"+
"itself is quite narrow, allowing for circulation of air in the tower",
	"trees",
"Tall evergreen trees can be seen out the windows of the tower",
	"sun",
"The golden sun can be seen out the windows of the tower, shining brightly",
	"walls",
"The walls of the tower are made of a simple grey stone.  Each individual\n"+
"block of stone looks incredibly heavy",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/tower6.c", "up",
	 "/players/zeus/realm/taus/tower5.c", "east",
	 "/players/zeus/realm/taus/tower2.c", "down",
 });
}


void init(){
	::init();
	add_action("e_dir", "east");
	add_action("e_dir2", "east");
	add_action("u_dir2", "up");
	add_action("d_dir2", "down");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

e_dir2(){	write("You enter the east room...\n\n");   }
u_dir2(){   write("You walk up the stairs...\n\n");   }
d_dir2(){   write("You walk down the stairs...\n\n");   }
