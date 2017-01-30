#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 
inherit "/players/vertebraker/closed/std/room";

reset(arg){

  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"The northeastern corner of the plains is shrouded in a very heavy\n"+
	"fog.  You can see no more than a few feet in front of you, and even\n"+
	"the ground is barely visible beneath you as tendrils of white float\n"+
	"around your feet.  The way to the north and east is obviously\n"+
	"blocked by the mountains, but you cannot discern what lies in any\n"+
	"other direction clearly.\n");
   no_exit_display = 1;
   add_item("mountains","Mountains block your way to the north and east.");
   add_item("fog","A dense fog restricts the range of your vision.");
       
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");

   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore to the west.");

   set_chance(10);
   add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/main","west");
   add_exit("/players/reflex/realms/coastline/plains4","south");
   add_exit("/players/reflex/realms/coastline/plains5","southwest");

   set_light(1);
   }
