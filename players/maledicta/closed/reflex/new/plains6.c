#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"The southwestern corner of the plains borders on a steep hill to\n"+
	"the west and sheer rock cliffs to the south.  To the east and north\n"+
	"the plains continue, and far to the north you can see a heavy fog.\n"+
	"The sound of the waves crashing into the other side of the hill is\n"+
	"very loud here, and the wind whistles through the natural barrier\n"+
	"created by the hill and cliff sides. There is a large cave to the\n"+
   "west.\n");
   no_exit_display = 1;
   add_item("hill","This hill conceals the coastline to the west.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("cliffs","These cliffs block off any path south.");
   add_item("cave","A HUGE cave with bones scattered about the ground before it.");
   add_item("bones","Thousands of bones. It is a chilling sight.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");
        
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");
	
   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline nearby.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains5","north");
   add_exit("/players/reflex/realms/coastline/plains3","east");
   add_exit("/players/reflex/realms/coastline/plains7","northwest"); 
   add_exit("/players/reflex/realms/coastline/plains4","northeast"); 
   add_exit("/players/maledicta/cont/rdragon/rooms/r1","cave");
   add_exit("/players/maledicta/cont/rdragon/rooms/r1","west");
       
   set_light(1);
   }
