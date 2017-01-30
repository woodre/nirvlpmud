/*************************************************************************
 * File:			shrine3.c
 * Function:		Room file for Dark Gauntlet area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2010 Sparrow
 *					All Rights Reserved
 * Source:			12/28/2010
 * Notes:			Room where muse is imprisoned
 *
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>

inherit "room/room";
  reset(arg){
  if(!arg){
	if(!present("muse", this_object())) {
	  move_object(clone_object("/players/sparrow/areas/darkGauntlet/npc/muse.c"), this_object());
    }
    set_light(-4);
    short_desc=MAG+"["+HIK+"Trial of the Black Willow"+NORM+MAG+"]"+NORM+"Music Shrine";
    long_desc="The forest has opened up into a small clearing. The night sky is clearly visible\n"+
              "even though there is no way of telling if it is actually night-time. In the center\n"+
              "of the clearing is a pile of glowing stones. The stones constantly hum with sound.\n"+
              "Delicate melodies and beautiful harmonies fill the air breaking the silence with\n"+
              "a dark and dramatic composition.\n";
    items=({
      "trees", 		"These black willow trees are unusually large reaching at least 50 feet into the\n"+
      		  		"sky.  The jet black bark seems to absorb all light.  The trees seem to be in a\n"+
      		  		"perpetual budding state, the buds giving off bright pinpoints of light",
      "darkness",	"The darkness is everywhere, concealing everything",
      "stones",	 	"The stone continue to make magical music"
    });
    dest_dir=({
      "/players/sparrow/areas/darkGauntlet/rms/forest3.c","out"
    });
  }
}

init()  {
 ::init();
  add_action("search_room","search");
  add_action("block","out");
}

search_room() {
  write("You find nothing of interest in the general area.\n");
  say (this_player()->query_name() +" searches the general area.\n");
  return 1;
}

block() {
  object monk;
  monk = present("muse", this_object());
  if(this_player()->query_npc()) {
    return;
  }
  if(monk) {
	write("Muse jumps to attack you from behind!\n");
	say("As "+capitalize(this_player()->query_name())+" tries to leave Muse attacks!\n");
	monk->attacked_by(this_player());
	return 1;
  }
  else {
	return 0;
  }
}