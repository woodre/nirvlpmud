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

reset(arg) {
 if(arg) return;
set_light(1);

short_desc = "A notorious life of "+HIR+"crime"+NORM+".";
long_desc =
  " This room is your first step on a long and notorious life of crime.\n"+
  "Simply type 'commit_crime' to see if crime does pay or if 'The System'\n"+
  "is as bad as everyone says it is.\n";
add_property("NT");

items = ({
"floor",
"A drab, uneventful looking floor",
});

dest_dir = ({
"/room/forest9.c",    "out",
});
}

init(){
::init();
  AA("commit_crime","commit_crime");
  AA("Smell","smell");
  AA("Search","search");
  AA("Listen","listen");
}

commit_crime()
{
  write("The police come in and haul "+TPN+" away to be arraigned.\n");
  say("The police run in the room with guns drawn and haul "+TPN+" away\n"+
  "in handcuffs");
  move_object(this_player(),"/players/tristian/realms/ClubFed/rooms/court.c");
  command("look",this_player()); 
  return 1;
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
  write("Strangely enough there is no sound in this room.\n");
  return 1;
}