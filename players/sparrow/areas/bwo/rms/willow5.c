/*************************************************************************
 * File:			willow5.c
 * Function:		Room file for Black Willow area
 * Author(s):		Sparrow@Nirvana
 * Copyright:		Copyright (c) 2009 Sparrow
 *					All Rights Reserved
 * Source:			10/6/2009
 * Notes:			Room is part of Willow Grove central square known as
 *					the District of the Dark Embrace             
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
    short_desc=YEL+"W"+NORM+"illow "+YEL+"G"+NORM+"rove "+YEL+"["+NORM+"Square Northwest"+YEL+"]"+NORM;
    long_desc="The Avenue of Shadows becomes the northwest corner of the town square.  This\n"+
    		  "area is also known as the District of the Dark Embrace.  It is here that the\n"+
    		  "priests from the Temple of the Black Willow spread the word of the Master of\n"+
    		  "Shadows to the common people at various times during the day.  The shadows are\n"+
    		  "more substantial here almost as if living creatures themselves.\n";
    items=({
      "square", 	"This is the northwest section of the town square, also known as\n"+
      				"the District of the Dark Embrace",
      "center", 	"This is the northwest section of the town center, also known as\n"+
      				"the District of the Dark Embrace",
      "shadows", 	"The shadows here are three dimensional having the consistancy of\n"+
      				"a thick fog",
      "shadow",     "The shadows here are three dimensional having the consistancy of\n"+
      				"a thick fog",
      "priests",	"Priests from the Temple of the Black Willow frequently use this\n"+
      				"area to further the word of the Master of Shadows",
    });
    dest_dir=({
      BWO+"willow7.c","east",
      BWO+"willow6.c","south",
      BWO+"willow3.c","west",
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
