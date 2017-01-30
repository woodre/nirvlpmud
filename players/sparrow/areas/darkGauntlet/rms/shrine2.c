/*************************************************************************
 * File:			shrine2.c
 * Function:		Room file for Dark Gauntlet area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2010 Sparrow
 *					All Rights Reserved
 * Source:			12/28/2010
 * Notes:			Room where herensugue is imprisoned
 *
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>

inherit "room/room";
  reset(arg){
  if(!arg){
	if(!present("herensugue", this_object())) {
	  move_object(clone_object("/players/sparrow/areas/darkGauntlet/npc/herensugue.c"), this_object());
    }
    set_light(-4);
    short_desc=MAG+"["+HIK+"Trial of the Black Willow"+NORM+MAG+"]"+NORM+" Star Shrine";
    long_desc="The forest has opened up into a small clearing. The night sky is clearly visible\n"+
              "even though there is no way of telling if it is actually night-time. In the center\n"+
              "of the clearing is a strange rune formed in the ground with white stones. It is very\n"+
              "quiet here, almost as if an unholy presence has scared everything away.\n";
    items=({
      "trees", 		"These black willow trees are unusually large reaching at least 50 feet into the\n"+
      		  		"sky.  The jet black bark seems to absorb all light.  The trees seem to be in a\n"+
      		  		"perpetual budding state, the buds giving off bright pinpoints of light",
      "darkness",	"The darkness is everywhere, concealing everything",
      "rune",		"It seems that the rune is some sort of binding spell.\n",
      "stones",	 	"The stones are perfectly round and form a rune on the ground\n"
    });
    dest_dir=({
      "/players/sparrow/areas/darkGauntlet/rms/forest2.c","out"
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
  monk = present("herensugue", this_object());
  if(this_player()->query_npc()) {
    return;
  }
  if(monk) {
	write("Herensugue jumps to attack you from behind!\n");
	say("As "+capitalize(this_player()->query_name())+" tries to leave Herensugue attacks!\n");
	monk->attacked_by(this_player());
	return 1;
  }
  else {
	return 0;
  }
}