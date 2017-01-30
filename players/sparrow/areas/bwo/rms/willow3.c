/*************************************************************************
 * File:			willow3.c
 * Function:		Room file for Black Willow area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2009 Sparrow
 *					All Rights Reserved
 * Source:			10/6/2009
 * Notes:			Room is a street in the town of Willow Grove named
 *					the Avenue of Shadows.                                   
 * Change History:
 *
 ************************************************************************/
#include <ansi.h>
#include "/players/sparrow/areas/bwo/include/defs.h"
#define terrain "city"
#define environment "outdoor"

inherit "room/room";
  reset(arg){
  if(!arg){
    set_light(1);
    short_desc=YEL+"W"+NORM+"illow "+YEL+"G"+NORM+"rove "+YEL+"["+NORM+"Avenue of Shadows"+YEL+"]"+NORM;
    long_desc="The Avenue of Shadows runs east to west as the main thoroughfare of Willow\n"+
    		  "Grove.  Pale golden paving stones fitted perfectly together stretch eastward\n"+
    		  "through the town closing in on the center square.  Shadows dance freely across\n"+
    		  "the ground as though they are controlled by some unseen will.  The citizens\n"+
    		  "pay these apparitions no heed as this phenomenon is commonplace in Willow Grove.\n";
    items=({
      "wall", 		"The western wall of Willow Grove is made from large blocks\n"+
      		  		"of obsidian polished to an almost mirrored finish",
      "stones", 	"The pale golden paving stones are fitted tightly together, bonded\n"+
                	"by a jet black mortar",
      "square", 	"The town square can be seen in the distance to the east",
      "center", 	"The town square can be seen in the distance to the east",
      "shadows", 	"The disembodied shadows flow across the stones a few inches from the ground",
      "shadow",     "The disembodied shadows flow across the stones a few inches from the ground",
      "citizens",	"The citizens carry out their daily activities seeminly oblivious to\n"+
      				"the shadows. You notice something strange about their eyes",
      "citizen",	"The citizens carry out their daily activities seeminly oblivious to\n"+
      				"the shadows. You notice something strange about their eyes",
      "eyes",		"As a citizen looks up at you you notice a swirling blackness in his iris",
    });
    dest_dir=({
      BWO+"willow5.c","east",
      BWO+"willow1.c","west",
    });
  }   
}

init()  {
 ::init();
  add_action("search_room","search");
}

search_room() {
  write("You find nothing of interest in the general area.\n");
  say (this_player()->query_name() +" searches the general area.\n");
  return 1;  
}
