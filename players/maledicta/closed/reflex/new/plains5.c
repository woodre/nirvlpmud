#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
 if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"The western edge of the plains is open in all directions except for\n"+
	"the mountains to the southwest.  The ocean surf rages to the west\n"+
	"and you can see a sandy beach in that direction.  The grasslands\n"+
	"continue in all other directions, but a heavy fog to the north\n"+
	"obscures your view.  The wind is at full strength here as it tears\n"+
	"across the plains.\n");
   no_exit_display = 1;
   add_item("beach","The surf crashes into the coastline to the west.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("beach","The water whips across the beach, tearing at anything there.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");
       
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");

   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline nearby.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains7","west");
   add_exit("/players/reflex/realms/coastline/main","north");
   add_exit("/players/reflex/realms/coastline/plains4","east");
   add_exit("/players/reflex/realms/coastline/plains6","south");
   add_exit("/players/reflex/realms/coastline/plains9","northwest"); 
   add_exit("/players/reflex/realms/coastline/plains8","northeast"); 
   add_exit("/players/reflex/realms/coastline/plains3","southeast"); 

   set_light(1);
   }


  