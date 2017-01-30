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
inherit "/players/tristian/realms/ClubFed/rooms/ClubFedRoom.c";
inherit "/players/vertebraker/closed/std/room.c";
inherit "/players/tristian/realms/ClubFed/cell_functions.c";

/*GLOBALS*/
int Lock;
int Door;

/*LOCAL*/
int cig;
int maybe;

reset(arg) {
  ::reset(arg);
  if(!present("convict",this_object())) Add_Monster();
  if(arg) return;
 
Lock = 1;
Door = 0;  
cig = 0;

set_light(1);

short_desc = HIR+"Club Fed"+NORM+" cellblock "+HIG+"'A' "+NORM+"cell "+HIY+"#109"+NORM; 

long_desc =
	" This is a standard cell in "+HIR+"Club Fed"+NORM+", the minimum security\n"+
	"facility where white collar criminals and celebrities come\n"+
	"to serve their sentences for their crimes against society.  It's\n"+
	"nicer than some hotels in the land, with a double bed, a full\n"+
	"window and a bathroom shared with the adjacent cell.\n";
add_property("NT");
add_property("PK");

items = ({

"window", 
	"A full double hung window that is bolted shut and covered with 'bars'\n",
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
"bed",
	"It's a Sealy Posturpedic mattress on a metal bed frame",
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
  RMS+"ha09",    "south",
});
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
  AA("Toss","toss");
}

Smell(str) {
  if(!str || str == "air") {
    write("The smells in the prison are fairly antiseptic.\n");
    return 1;
}
    return 1;
}

Search() {
  write("You find nothing special. Perhaps 'toss'ing the cell would be more appropriate.\n");
	return 1;
}

Toss(str)
{
  if (present("convict", this_object()))
  {
    write("You can't toss the cell while it is occupied, unless you wanna get shanked!\n");
    return 1;
  }
  if(!str)
  {
    notify_fail("Toss what?\n");
    return 0;
  }
  if(str != "cell")
  {
    notify_fail("You may only toss the cell.\n");
    return 0;
  }
  maybe = random(100);
  if(cig == 1 || maybe <= 80)
  {
    write("You toss the cell but don't find anything.\n");
    say(TPN+" tosses the cell but doesn't find anything.\n");
    cig = 1;
    return 1;
  }
  else
  {
    write("You search behind the bed, in the closet and just as your about to give up\n"+
    "you find a single cigarette behind the picture.\n\n\n");
    say (TPN+" tosses the cell and finds a cigarette.\n");
        
    cig=clone_object(OBJ+"cig.c");
    move_object(cig,this_object());
    command("look",TP);
    cig = 1;
      
    return 1;
  }
}
   
Listen() {
  write("The sounds of a somewhat atypical prison, The guard walking up\n"+
  "and down the hall, and a slightly mechanical buzz are in the air.\n");
  return 1;
}