/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2014 Tristian
//                  All Rights Reserved.
//  Function:     Prison High-Level Area
//  Create Date:  2014.04.10
//	Thanks to everyone who helped me...
//
//	Change History:
// 
*/

#include "/players/tristian/lib/supermaxdefine.h"
inherit "/players/tristian/realms/supermax/rooms/supermaxRoom.c";
inherit "/players/vertebraker/closed/std/room.c";
inherit "/players/tristian/realms/supermax/cell_functions.c";

/*LOCAL*/
int random;

reset(arg) {
  ::reset(arg);
/*  if(!present("convict",this_object())) Add_Monster();    */
  if(arg) return;

set_light(1);

long_desc =
	HIK+"####"+HIY+"*"+HIK+"####\n"+
	HIK+"##"+HIR+"C"+NORM+"-|-"+HIR+"C"+HIK+"##"+NORM+"\n"+
	HIK+"##"+HIR+"C"+NORM+"|"+HIK+"#"+NORM+"|"+HIR+"C"+HIK+"##"+NORM+"\n"+
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
  
});

dest_dir = ({
  RMS+"center/cellAhall",    "north",
  RMS+"hall-a09",   "south",
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

  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
  AA("Examine","examine");
  AA("Quit","quit");
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Examine(str) {
  if(!str || str == "room" || str == "cell") {
    write("This is a pod of cell block A in the SuperMax prison.  There\n"+
		  "is a thin metal cot with a threadbare mattress, a steel desk\n"+
		  "bolted to the floor and a combo toilet sink fixture made of\n"+
		  "stainless steel.  And of course, bars everywhere.\n");
    return 1;
}
    return 1;
}

Search() {
    write("You find nothing special. Perhaps 'toss'ing the cell would be more appropriate.\n");
	 return 1;
}

Listen() {
    write("The sounds of a typical prison, The guard walking up\n"+
    "and down the hall, and a slightly mechanical buzz are in the air.\n");
    return 1;
}

Quit() {
	write(HIR+BLINK+"This is prison, you're not getting out that easy.  You did the crime,\n"+
		  "now serve your time."+NORM+"\n\n");
	return 1;
}


