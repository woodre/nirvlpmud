/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison High-Level Area
//  Create Date:  2014.04.10
//	Thanks to everyone who helped me...
// //
//	Change History:
*/

#include "/players/tristian/lib/supermaxdefine.h"
inherit "/players/tristian/realms/supermax/rooms/supermaxRoom.c";
inherit "/players/vertebraker/closed/std/room.c";
inherit "/players/tristian/realms/supermax/cell_functions.c";

/*GLOBALS*/
int Lock;
int Door;

/*LOCAL*/
int random;

reset(arg) {
  ::reset(arg);
/*  if(!present("convict",this_object())) Add_Monster();    */
  if(arg) return;

Lock = 1;
Door = 0; 

set_light(1);

long_desc =
	HIK+"####"+NORM+"|"+HIK+"####\n"+
	HIK+"##"+HIR+"C"+NORM+"-|-"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+HIY+"*"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"|"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"|"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"|"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"|"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"|"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"---"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"#########\n"+NORM;
	
add_property("NT");
add_property("PK");

items = ({


"bars",
	HIK+"---------------------------------------------------\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"|      ||     ||     ||     ||     ||     ||      |\n"+
	"---------------------------------------------------\n"+NORM,
"cot",
	"It's a simple metal frame with a thin threadbare mattress",
"sealy",
	"A Sealy Posturpedic mattress, much higher quality than a standard prison mattress",
"frame",
	"A simple metal bed frame",
"mattress",
  "A Sealy Posturpedic mattress, much higher quality than a standard prison mattress",
"door",
	"A cell door, covered with bars and it has a lock",
"bathroom",
  "At least it appears to be a bathroom.  The door is closed from the other side,\n"+
"perhaps in use by the next cell's tenant",    
});

dest_dir = ({
  RMS+"pod-a07",    "west",
  RMS+"hall-a08",	"north",
  RMS+"hall-a06",	"south",
});
}

short(){ 
switch(random(8)){
   case 0: random = ""+HIR+"Alcatraz Federal Penitentary"+NORM+"";
   break;
   case 1: random = ""+HIM+"Attica State Prison"+NORM+"";
   break;
   case 2: random = ""+HIC+"Fort Leavenworth Disciplinary Barracks"+NORM+"";
   break;
   case 3: random = ""+HIR+"Andersonville"+NORM+"-Confederate Civil War Prison";
   break;
   case 4: random = ""+HIG+"Sing Sing State Prison"+NORM+"";
   break;
   case 5: random = ""+HIB+"Rikker's Island State Prison"+NORM+"";
   break;
   case 6: random = ""+HIY+"San Quinton State Prison"+NORM+"";
   break;
   case 7: random = ""+HIG+"Pelican Bay State Prison"+NORM+"";
   break;
   case 8: random = ""+HIR+"Shawshank State Prison"+NORM+"";
   break; 
}

   return ""+random+"";
}

init() {
::init();
  AA("East","east");
  AA("Lock","lock");
  AA("Unlock","unlock");
  AA("Open","open");
  AA("Close","close");
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
  AA("Examine","examine");
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Examine(str) {
  if(!str || str == "room" || str == "hall") {
    write("This is a hall of cell block A in the SuperMax prison.  The\n"+
		  "walls are concrete and painted a dull grey color that envokes a\n"+
		  "feeling of hopelessness.\n");
    return 1;
}
    return 1;
}

Search() {
    write("You find nothing special.\n");
	 return 1;
}

Listen() {
    write("The sounds of a typical prison, The guard walking up\n"+
    "and down the hall, and a slightly mechanical buzz are in the air.\n");
    return 1;
}



