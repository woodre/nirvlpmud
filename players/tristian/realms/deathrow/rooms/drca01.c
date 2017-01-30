/*
//  Created:      Tristian@Nirvana
//  Copyright:    Copyright (c) 2006 Tristian
//                  All Rights Reserved.
//  Function:     Prison Legend Level Area
//  Create Date:  2006.16.07
//	Thanks to everyone who helped me...
*/

#include "/players/tristian/lib/DR_define.h"
inherit "/players/tristian/realms/Death Row/rooms/DeathRowRoom.c";
inherit "/players/vertebraker/closed/std/room.c";
inherit "/players/tristian/realms/Death Row/cell_functions.c";

/*GLOBALS*/
int Lock;
int Door;

/*LOCAL*/

int maybe;

reset(arg) {
  ::reset(arg);
  if(!present("convict",this_object())) Add_Monster();
  if(arg) return;

Lock = 1;
Door = 0; 
cig = 0;

set_light(1);

short_desc = HIR+"Death Row"+NORM+" cell "+HIY+"#101"+NORM; 

long_desc =
	" This is death row, the cells are sparse, a thin cot, steel\n"+
	"toilet and sink with a polished steel plate for a mirror.\n"+
	"The walls are painted gray, the floor is bare concrete and\n"+
	"nothing about the space feels inviting.\n
	";
add_property("NT");

items = ({

"window", 
	"A full double hung window ,however, it is bolted shut and covered with 'bars'\n",
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
	"Its a sealy posturpedic mattress on a metal bed frame",
"sealy",
	"A Sealy Posturpedic mattress, much higher quality than standard prison mattress",
"frame",
	"A simple metal bed frame",
"mattress",
  "A Sealy Posturpedic mattress, much higher quality than standard prison mattress",
"door",
	"A cell door, covered with bars and it has a lock",  
});

dest_dir = ({
  RMS+"hall_A_01",    "south",
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

Quit()
{
  write(HIR+"\n\nThis is DEATH ROW, you had to be hard to get here, so be hard now and suck it up\n"+
             "it's kill or be killed in here, quitting is not allowed.\n\n"+NORM);
  return 1;
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
  maybe = random(5);
  if(cig == 1 || maybe != 1)
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
    say (TPN +" tosses the cell and finds a cigarette.\n");
        
    cig=clone_object(OBJ+"cig.c");
    move_object(cig,this_object());
    command("look",this_player());
    cig = 1;
      
    return 1;
  }
}
Listen() {
    write("The sounds of a somewhat atypical prison, The guard walking up\n"+
    "and down the hall, and a slightly mechanical buzz are in the air.\n");
    return 1;
}



