/*************************************************************************
 * File:			shrine1.c
 * Function:		Room file for Dark Gauntlet area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2010 Sparrow
 *					All Rights Reserved
 * Source:			12/28/2010
 * Notes:			Room where treluna is imprisoned
 *
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>

inherit "room/room";
  reset(arg){
  if(!arg){
	if(!present("treluna", this_object())) {
	  move_object(clone_object("/players/sparrow/areas/darkGauntlet/npc/treluna1.c"), this_object());
    }
    set_light(-1);
    short_desc=MAG+"["+HIK+"Trial of the Black Willow"+NORM+MAG+"]"+NORM+" Moon Shrine";
    long_desc="The forest has opened up into a small clearing. The night sky is clearly visible\n"+
              "even though there is no way of telling if it is actually night-time. In the center\n"+
              "of the clearing is a small pool of liquid reflecting the moon perfectly. It is very\n"+
              "quiet here, almost as if an unholy presence has scared everything away.\n";
    items=({
      "trees", 		"These black willow trees are unusually large reaching at least 50 feet into the\n"+
      		  		"sky.  The jet black bark seems to absorb all light.  The trees seem to be in a\n"+
      		  		"perpetual budding state, the buds giving off bright pinpoints of light",
      "darkness",	"The darkness is everywhere, concealing everything",
      "pool",		"The pool is filled with a heavy metallic liquid that is silver in color.\n"
    });
    dest_dir=({
      "/players/sparrow/areas/darkGauntlet/rms/forest1.c","out"
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
  monk = present("treluna", this_object());
  if(this_player()->query_npc()) {
    return;
  }
  if(monk) {
	write("Treluna jumps to attack you from behind!\n");
	say("As "+capitalize(this_player()->query_name())+" tries to leave Treluna attacks!\n");
	monk->attacked_by(this_player());
	return 1;
  }
  else {
	return 0;
  }
}