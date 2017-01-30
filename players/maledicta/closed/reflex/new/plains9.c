#include "/players/reflex/lib/include/ansi.h"

#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"This is the northwestern edge of the coastline.  Mountains block\n"+
	"any passage north, and the ocean opens up to the west.  Waves crash\n"+
	"violently into the shore, and the wind almost takes you off your\n"+
	"feet.  Any movement is a battle for footing, and you feel that if\n"+
	"you slip it will not be easy to get back up.  There is a heavy fog\n"+
	"here that gets inpenetrable to the east.\n");
   no_exit_display = 1;
 
    add_item("mountains", "Tall mountains block the coastline to the north.");
    add_item("ocean", "The ocean storms violently to the west.");
    add_item("waves", "Huge waves crash into the shoreline, devouring it slowly.");
    add_item("shore", "This is a sandy beach in the midst of a storm.");
	 add_item("fog", "The fog is absolutely impenetrable to the east..");
    add_smell("main","The saltwater smell of the sea permeates the air around you.");
	 add_smell("wind","The air smells very moist from the sea.");
 
    add_listen(
	 "main","Thunder rumbles overhead as the sea storm builds.");
	 add_listen(
    "waves","Waves crash violently into the shore.");
	
   
   set_chance(10);
   add_msg("Waves crash into the shoreline.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/main","east");
   add_exit("/players/reflex/realms/coastline/plains7","south");
   add_exit("/players/reflex/realms/coastline/plains5","southeast"); 
   set_light(1);
   }


  
