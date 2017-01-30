/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2005 Tristian
//                  All Rights Reserved.
//  Function:     Prison Mid-Level Area
//  Create Date:  2005.06.03
//	Thanks to everyone who helped me...
//  especially Illarion & Vertebraker
*/

#include "/players/tristian/lib/ClubFeddefine.h"
inherit "/players/tristian/realms/ClubFed/cell_functions.c";
inherit "/players/vertebraker/closed/std/room.c";

/*GLOBALS*/
int Lock;
int Door;


reset(arg) {
	if(arg) return;

Lock = 0;
Door = 1;
set_light(1);

short_desc = HIR+"Club Fed"+NORM+" cellblock "+HIG+"'A'"+NORM+" Hallway"; 

long_desc =
	" This is a hallway in Cellblock 'A' inside "+HIR+"Club Fed"+NORM+", the minimum\n"+
	"security facility where white collar criminals and celebrities come\n"+
	"to serve their sentences for their crimes versus society. There\n"+
	"are cells along the north wall and a gallery along the south. To\n"+
	"the east are the showers, be careful in the showers, they have\n"+
	"been known to be the breeding grounds of violence.\n";
add_property("NT");
add_property("PK");

items = ({
"cells", 
	"The rooms where the inmates stay, there is a door and it is covered in 'bars'\n",
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
"gallery",
	"The open area between cellblocks, there are 'bars' that prevent anything\n"+
	"from being thrown into that space\n",
"door",
	"A cell door, covered with 'bars' and it has a lock",
"wall",
  "A concrete wall, painted in a drab grey color",   
});

dest_dir = ({
  RMS+"ca10",    "north",
  RMS+"hashower","east",
  RMS+"ha09",    "west",
});
}

init() {
::init();
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
  AA("Unlock","unlock");
  AA("Lock","lock");
  AA("North","north");
  AA("Open","open");
  AA("Close","close");
}


Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Search() {
  write("You find nothing special.\n");
	return 1;
}

Listen() {
  write("The sounds of a somewhat atypical prison, The guard walking up\n"+
  "and down the hall, and a slightly mechanical buzz are in the air.\n");
  return 1;
}