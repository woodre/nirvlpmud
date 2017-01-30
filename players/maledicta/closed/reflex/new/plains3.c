#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 
inherit "/players/vertebraker/closed/std/room";

reset(arg){

  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"The grasslands stretch off endlessly to the north, fading into a\n"+
	"low fog at the end of your vision.  To the south stand sheer\n"+
	"cliffs, reaching up the sides of the mountains above them.  The\n"+
	"ground is soft and sandy, and the scrubgrass is very deep here,\n"+
	"rising above your hips.  The storm raging above you seems as if\n"+
	"its fighting the mountain cliffs, surging in an attempt to get\n"+
	"past.\n");
   no_exit_display = 1;
   add_item("mountains","Tall mountains rise to the south and east, blocking you.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("cliffs","The cliffs to the south are too steep to climb.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");
       
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");

   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline in the distance.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains6","west");
   add_exit("/players/reflex/realms/coastline/plains4","north");
   add_exit("/players/reflex/realms/coastline/plains2","east");
   add_exit("/players/reflex/realms/coastline/plains5","northwest"); 
   add_exit("/players/reflex/realms/coastline/plains1","northeast"); 
  
   set_light(1);
   }
