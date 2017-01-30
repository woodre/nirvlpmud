#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 
inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"This is the western coastline.  Waves crash into the shore with\n"+
	"sound and fury as the storm rages on around you.  You can barely\n"+
	"keep your footing here as the wind and ocean spray hammers you into\n"+
	"submission.  The sand underfoot is saturated with seawater and you\n"+
	"feel your boots sinking in with every step.  Visibility is almost\n"+
	"non-existant here, but you can tell there is a hill to the south,\n"+
	"and the ocean is to the west.\n");
   no_exit_display = 1;
   add_item("hill","This hill blocks your way to the south.");
   add_item("plains","Wide open plains lead eastwards towards the mountains.");
   add_item("waves","Huge waves crash into the shoreline, devouring it slowly.");
   add_item("shore","This is a sandy beach in the midst of a storm.");
	add_item("fog","The fog is absolutely inpenetrable to the north...");

   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");
	
   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline.");
	add_msg("You hear a whistling noise as the winds whip through the"+            " grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains9","north");
   add_exit("/players/reflex/realms/coastline/plains5","east");
   add_exit("/players/reflex/realms/coastline/main","northeast");
   add_exit("/players/reflex/realms/coastline/plains6","southeast");
   set_light(1);
   }

  
