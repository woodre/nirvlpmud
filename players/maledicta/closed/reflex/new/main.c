#include "/players/reflex/lib/include/ansi.h"
#include "security.h" 

inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"Fog is so thick here that you cannot see more than a foot in front\n"+
	"of your face.  You know there are mountains to the north, but\n"+
	"beyond that you do not know a thing.  The ground under your feet is\n"+
	"soft and sandy, and the wind howls around you, screaming in protest\n"+
	"at the rock walls along the mountains.\n");
   no_exit_display = 1;
   add_item("fog","A dense fog restricts the range of your vision.");
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");
	
   add_listen("default","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore to the west.");
	
   set_chance(40);
   add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains9","west");
   add_exit("/players/reflex/realms/coastline/plains8","east");
   add_exit("/players/reflex/realms/coastline/plains5","south");
   add_exit("/players/reflex/realms/coastline/plains7","southwest"); 
   add_exit("/players/reflex/realms/coastline/plains4","southeast"); 
   set_light(0);
   }

  