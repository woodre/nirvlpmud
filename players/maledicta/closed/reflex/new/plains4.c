#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 
inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"This is the center of the plains, the space around you is entirely\n"+
	"open in all directions with the exception of a small hill blocking\n"+
	"any passage to the northeast.  North the grasslands continue into\n"+
	"a heavy fog, and the grasslands continue in all other directions\n"+
	"as far as the eye can see.  You can see the coastline in the\n"+
	"distance to the west, and almost make out the waves crashing into\n"+
	"the shore.\n");
   no_exit_display = 1;
   add_item("coastline","You can almost see the coast to the west.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("hill","This hill blocks you to the northeast.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");
        
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");
	
   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline in the distance.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains5","west");
   add_exit("/players/reflex/realms/coastline/plains8","north");
   add_exit("/players/reflex/realms/coastline/plains1","east");
   add_exit("/players/reflex/realms/coastline/plains3","south");
   add_exit("/players/reflex/realms/coastline/main","northwest"); 
   add_exit("/players/reflex/realms/coastline/plains2","southeast"); 
  add_exit("/players/reflex/realms/coastline/plains6","southwest"); 

   set_light(1);
   }


