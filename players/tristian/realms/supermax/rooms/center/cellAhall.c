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
/*inherit "/players/tristian/realms/supermax/cell_functions.c";*/

#define ROOMDM "/players/tristian/realms/supermax/obj/roomDM.c"

/*LOCAL*/
int random;

reset(arg) {
  ::reset(arg);
/*  if(!present("convict",this_object())) Add_Monster();    */
  if(arg) return;

set_light(1);

long_desc =
 
	  HIW+"         D\n"+
      HIK+"   ######"+HIW+"|"+HIK+"######\n"+
          "   ###"+HIW+".-----."+HIK+"###\n"+
          "   ##"+HIW+"/   |   \\"+HIK+"##\n"+
          "   #"+HIW+"/    |    \\"+HIK+"#\n"+
      HIW+"  B-"+HIW+"|---"+HIM+"GGG"+HIW+"---|-C\n"+
      HIK+"   #"+HIW+"\\    |    /"+HIK+"#\n"+
          "   ##"+HIW+"\\   |   /"+HIK+"##\n"+
          "   ###"+HIW+"'-----'"+HIK+"###\n"+
          "   ######"+HIM+"*"+HIK+"######\n"+
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
  RMS+"center/center_hall25",    "north",
  RMS+"centerA",	             "south",
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
  AA("South","south");
  AA("Lock","lock");
  AA("Unlock","unlock");
  AA("Open","open");
  AA("Close","close");
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
  AA("Examine","examine");
}

Unlock() {
  if( !ROOMDM->query_unlockedA() ) {
    write("The door is locked, and it appears to be unlocked from elsewhere.\n");
    return 1;
  }
}

South() {
  if( !ROOMDM->query_unlockedA() ) {
    write("The door is locked, and it appears to be unlocked from elsewhere.\n");
    tell_room(environment(this_player()), "UnlockedA = "+ROOMDM->query_unlockedA()+"\n");
    return 1;
  }
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Examine(str) {
  if(!str || str == "room" || str == "shack") {
    write("This is the last room in the center pod before you enter cell-\n"+
		  "block A.  There is a closed and locked door to the south and\n"+
		  "it appears to be unlocked from elsewhere.\n");
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