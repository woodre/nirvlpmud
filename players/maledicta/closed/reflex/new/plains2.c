#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
	"You are at the southeastern corner of the western coastal plains.\n"+
	"South and east are blocked by tall mountains, while to the north\n"+
	"and west the plains continue on.  You can hear the sounds of waves\n"+
	"crashing into the shoreline to the west, and rain falls from the\n"+
	"skies overhead, soaking you to the bone.  All around you is soggy\n"+
	"grasslands, and the wind is whipped to a frenzy here by the tall\n"+
	"mountainsides south and east of you.\n");
   add_item("mountains","Tall mountains rise to the south and east, blocking you.");
   add_item("plains","Wide open plains lead out towards the coastline.");
   add_item("grasslands","Scrub grass grows up through the somewhat sandy soil here.");
   add_item("skies","Visibility is reduced around you as the grey sky above dumps\n"+
	                 "rain down on everything.\n");
	add_item("hill","A small but steep hill blocks your way to the north.");
   no_exit_display = 1;
      
   add_smell("main","The saltwater smell of the sea permeates the air around you.");
	add_smell("wind","The air smells very moist from the sea.");
	
   add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	add_listen("waves","Waves crash violently into the shore in the distance.");
	
   set_chance(10);
   add_msg("Waves crash into the shoreline in the distance.");
	add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
   add_exit("/players/reflex/realms/coastline/plains1","north");
   add_exit("/players/reflex/realms/coastline/plains3","west");
   add_exit("/players/reflex/realms/coastline/plains4","northwest"); 

   set_light(1);
   }
