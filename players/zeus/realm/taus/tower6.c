inherit "room/room";	/*  tower6.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport;

reset(arg){

  teleport = 0;  if(random(TFL_TLP)) teleport = 1;

  if(!present("auseth")) MO(CO("/players/zeus/realm/NPC/auseth.c"), TO);

  if(arg) return;

 set_no_clean(1);
 short_desc="Auseth's Tower";
 long_desc=
"This is the top floor of the tower.  The centerpiece of the room is a\n"+
"table, and it seems everything else has been placed around it.  Some\n"+
"shelves are standing against the walls, containing glass jars and vials\n"+
"filled with random things.  A door on the east wall leads to a side room.\n"+
"A few gaping windows provide ample light for the room.  The staircase\n"+
"on the west wall leads back down to the second floor library.\n";
 set_light(1);
 items=({
	"table",
"The large table seems to serve multiple purposes.  At the moment there\n"+
"are some plants and potions sitting on it, and an open scroll.  A few\n"+
"dark red stains are visible in the center of the table",
	"stains",
"The dark red stains on the table are clearly blood, and look like they\n"+
"have been a part of this table for a very long time",
	"plants",
"The plants on the table are green and have been chopped up quite a bit",
	"potions",
"There are a few potions sitting on the table, all of which are clear",
	"scroll",
"The open scroll on the table is blank",
	"shelves",
"The shelves in the room contain many glasses, jars, potions, plants,\n"+
"books, scrolls, and everything else a wizard might need",
	"glasses",
"Some glasses are sitting on the shelves in the room",
	"jars",
"Some labeled jars are sitting on the shelves.  They are filled with\n"+
"multicolored solutions, specimen samples, and many other things",
	"books",
"A few books are among that many things on the shelves",
	"scrolls",
"Numerous scrolls are on the shelves in the room.  Most of them are\n"+
"in very nice condition",
	"vials",
"There are numerous vials filled with colorful liquids on the shelves",
	"door",
"The simple oak door leads to a side room to the east",
	"windows",
"There are a few simple, narrow windows in the walls of the tower, which\n"+
"provide you with a limited view of the Fallen Lands",
	"staircase",
"The wide staircase that curves along the west wall leads back down to\n"+
"the second floor of the tower",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/tower7.c", "east",
	 "/players/zeus/realm/taus/tower4.c", "down",
 });
}


void init(){
	::init();
	add_action("e_dir", "east");
	add_action("e_dir2", "east");
	add_action("d_dir2", "down");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

e_dir2(){	
  if(present("auseth")){
    write("Auseth says:  No, you can't go in there!\n");
    return 1;
  }
  write("You enter the east room...\n\n");  
}

d_dir2(){   write("You walk down the stairs...\n\n");   }
