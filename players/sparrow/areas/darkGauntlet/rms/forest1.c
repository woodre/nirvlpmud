/*************************************************************************
 * File:			forest1.c
 * Function:		Room file for Dark Gauntlet area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2010 Sparrow
 *					All Rights Reserved
 * Source:			12/20/2010 Happy Birthday to Me!
 * Notes:			Room is a random forest room for dark gauntlet
 *
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>

inherit "room/room";
  reset(arg){
  if(!arg){
    set_light(-1);
    short_desc=MAG+"["+HIK+"Trial of the Black Willow"+NORM+MAG+"]"+NORM+" Forest";
    long_desc="The forest is dark, very dark. The only light that permiates the darkness is the\n"+
		      "twinkling pinpoints of light that eminates from the buds of the trees. The darkness\n"+
		      "seems to press down on you from every angle. Evil whispers float through the trees \n"+
	          "promising power and wealth. Ancient evil resides in this forest, powerful beings\n"+
    		  "dwell within these trees. The forest opens up in every direction.\n";
    items=({
      "trees", 		"These black willow trees are unusually large reaching at least 50 feet into the\n"+
      		  		"sky.  The jet black bark seems to absorb all light.  The trees seem to be in a\n"+
      		  		"perpetual budding state, the buds giving off bright pinpoints of light",
      "darkness",	"The darkness is everywhere, concealing everything",
    });
    dest_dir=({
      "/players/sparrow/areas/darkGauntlet/rms/forest2.c","north",
      "/players/sparrow/areas/darkGauntlet/rms/forest3.c","east",
      "/players/sparrow/areas/darkGauntlet/rms/forest4.c","south",
      "/players/sparrow/areas/darkGauntlet/rms/forest2.c","west",
      "/players/sparrow/areas/darkGauntlet/rms/forest3.c","northeast",
      "/players/sparrow/areas/darkGauntlet/rms/forest4.c","northwest",
      "/players/sparrow/areas/darkGauntlet/rms/forest2.c","southeast",
      "/players/sparrow/areas/darkGauntlet/rms/forest3.c","southwest",
    });
  }
}

init()  {
 ::init();
  add_action("search_room","search");
  add_action("block","north");
  add_action("block","east");
  add_action("block","south");
  add_action("block","west");
  add_action("block","northeast");
  add_action("block","northwest");
  add_action("block","southeast");
  add_action("block","southwest");
}

search_room() {
  write("You find nothing of interest in the general area.\n");
  say (this_player()->query_name() +" searches the general area.\n");
  return 1;
}

block() {
  object shrine;
  object monk;
  monk = present("Black Willow Monk", this_object());
  if(this_player()->query_npc()) {
    return;
  }
  if(!monk) {
    if(random(100) > 65) {
	  switch(random(10)) {
		case 0..4:
		  monk = clone_object("/players/sparrow/areas/bwo/npc/bwo_template.c");
		  move_object(monk,environment(this_player()));
		break;
		case 5..7:
		  monk = clone_object("/players/sparrow/areas/bwo/npc/bwo_template.c");
		  move_object(monk,environment(this_player()));
		  monk = clone_object("/players/sparrow/areas/bwo/npc/bwo_template.c");
		  move_object(monk,environment(this_player()));
		break;
		default:
		  monk = clone_object("/players/sparrow/areas/bwo/npc/bwo_template.c");
		  move_object(monk,environment(this_player()));
		  monk = clone_object("/players/sparrow/areas/bwo/npc/bwo_template.c");
		  move_object(monk,environment(this_player()));
		  monk = clone_object("/players/sparrow/areas/bwo/npc/bwo_template.c");
		  move_object(monk,environment(this_player()));
	  }
    }
  }
  if(monk) {
	write("The Black Willow Monk attacks you in a blinding flash!\n");
	say("As "+capitalize(this_player()->query_name())+" tries to leave a Black Willow Monk attacks!\n");
	monk->attacked_by(this_player());
	return 1;
  }
  else {
	if(random(10) < 3) {
      switch(random(3)) {
        case 0:
          shrine = find_object("/players/sparrow/areas/darkGauntlet/rms/shrine1.c");
          if(!shrine) {
		    shrine = clone_object("/players/sparrow/areas/darkGauntlet/rms/shrine1.c");
	      }
        break;
        case 1:
          shrine = find_object("/players/sparrow/areas/darkGauntlet/rms/shrine2.c");
		  if(!shrine) {
		    shrine = clone_object("/players/sparrow/areas/darkGauntlet/rms/shrine2.c");
	      }
        break;
        case 3:
          shrine = find_object("/players/sparrow/areas/darkGauntlet/rms/shrine3.c");
	      if(!shrine) {
		    shrine = clone_object("/players/sparrow/areas/darkGauntlet/rms/shrine3.c");
	      }
        break;
      }
      write("You sneak through a secret path in the forest.\n");
      say(capitalize(this_player()->query_name())+" sneaks off through a secret path in the forest.\n");
      move_object(this_player(), shrine);
      return 1;
    }
	return 0;
  }
}