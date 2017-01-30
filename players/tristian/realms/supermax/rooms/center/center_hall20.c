/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2014 Tristian
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
 
	  HIW+"         D\n"+
      HIK+"   ######"+HIW+"|"+HIK+"######\n"+
          "   ###"+HIW+".-----."+HIK+"###\n"+
          "   ##"+HIW+"/   |   \\"+HIK+"##\n"+
          "   #"+HIW+"/    |    \\"+HIK+"#\n"+
      HIW+"  B-"+HIW+"|---"+HIM+"GGG"+HIW+"---|-C\n"+
      HIK+"   #"+HIW+"\\    |    "+HIM+"*"+HIK+"#\n"+
          "   ##"+HIW+"\\   |   /"+HIK+"##\n"+
          "   ###"+HIW+"'-----'"+HIK+"###\n"+
          "   ######"+HIW+"|"+HIK+"######\n"+
      HIW+"         A\n"+NORM;

	
add_property("NT");
add_property("PK");

items = ({

  "monitors",
	"Video monitors showing all angles of the prison from the cameras mounted on all walls",
  "computer",
	"Computers that are running all the systems in the prison, they allow doors to be opened\n"+
    "and closed remotely.",
  "computers",
	"Computers that are running all the systems in the prison, they allow doors to be opened\n"+
    "and closed remotely.",
  "consoles",
	"Computers that are running all the systems in the prison, they allow doors to be opened\n"+
    "and closed remotely.",

});

dest_dir = ({
  RMS+"center/center_hall16",    "northeast",
  RMS+"center/center_hall21",	 "southwest",
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
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Examine(str) {
  if(!str || str == "room") {
    write("This one of the perimeter rooms in the pod, there are tables for\n"+
		  "inmates to sit at and TV's on the walls for the convicts to watch.\n"+
		  "This is basically a common room where inmates gather to pass the other-\n"+
          "wise boring existence of prison. Watch yourself out here, its easy to\n"+
          "shanked.\n");
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

Quit() {
	write(HIR+BLINK+"This is prison, you're not getting out that easy.  You did the crime,\n"+
		  "now serve your time."+NORM+"\n\n");
	return 1;
}