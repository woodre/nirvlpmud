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
inherit "/players/vertebraker/closed/std/room.c";

/*LOCAL*/
int wallet;
int mygold;

reset(arg) {
 ::reset(arg);
 if(arg) return;

wallet = 0;
set_light(1);

short_desc = HIR+"Club Fed"+NORM+" Warden's Office";
long_desc =
  " This is where the warden sits and watches all the cons at Club Fed.\n"+
  "The office is plush and has new furniture including a massive oak desk,\n"+
  "swivel chair, a stand with an American flag, and the flag for the Division\n"+
  "of Corrections.  The office is neat and clean and radiates power.\n";

items = ({
"desk",
"The desk is opulant and radiates the power of the office if sits in, maybe you should rifle though it.",
"chair",
"A leather high back swivel office chair",
"swivel chair",
"A leather high back swivel office chair",
"flag",
"An american flag, the stars and bars, ole red white and blue",
"american flag",
"An american flag, the stars and bars, ole red white and blue",
"division flag",
"A flag showing the division of correction emblem and motto",
});

    if(!present("warden",this_object()))
        move_object(
            clone_object("/players/tristian/realms/ClubFed/mobs2/warden.c"),
        this_object());

dest_dir = ({
RMS+"parole", "north",
});
}

init(){
::init();
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
  AA("Rifle","rifle");
}
    
Smell(str) {
  if(!str || str == "air") {
  write("There are no smells present in the air.\n");
  return 1;
}
  return 1;
}

Search() {
  write("You find nothing special.\n");
  return 1;
}

Listen() {
  write("You can hear the background din of the yard out his window and\n"+
  "the hum of the air conditioning vents.\n");
  return 1;
}

Rifle(str) {
  if (present("warden", this_object()))
  {
    write("You can't rifle through the warden's desk with him sitting at it unless you want to get whacked with his billy club.\n");
    return 1;
  }
  if(!str)
  {
    notify_fail("Rifle through what?\n");
    return 0;
  }
  if(str != "desk")
  {
    notify_fail("You may only rifle through the desk.\n");
    return 0;
  }
   if(wallet == 1)
  {
    write("You rifle through the desk but someone already stole the warden's wallet.\n");
    say(TPN+" rifles through the desk but doesn't find anything.\n");
    return 1;
  }
  else
  {
    write("You rifle through the desk, find the warden's wallet and steal his money.\n\n");
    say (TPN +" rifles though the desk and steals the money from the Warden's wallet.\n");
        wallet = 1;   
		
	mygold = clone_object("obj/money"); 
	mygold->set_money( 1000 + random(1000));
    move_object(mygold,this_object());
    command("look",TP);
    return 1;
  }
}