#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg){
  if(arg) return;
    set_short("Western Coastal Plains");
    set_long(
        "You are on the edge of the western coastal plains.  Scrub grass\n"+
	"stretches westward across the plains ending in the coastline in\n"+
	"the distance.  The sky is a very sullen grey color overhead, and\n"+
	"cold rain pours down torrentially everywhere, saturating the grass\n"+
	"beneath your feet.  To the north is a small hill blocking you, but\n"+
	"there is a path eastward into the mountains, and you can go west\n"+
	"and south onto the plains.\n");
    add_item("path","This is a muddy path leading into the mountains to the east.");
    add_item("plains","Wide open plains lead out towards the coastline.");
    add_item("grass","Scrub grass grows up through the somewhat sandy soil here.");
    add_item("sky",
    "Visibility is reduced around you as the grey sky above dumps\n"+
	 "rain down on everything.");
	 add_item("hill","A small but steep hill blocks your way to the north.");
        
    add_smell("main","The saltywater smell of the sea permeates the air around you.");
	 add_smell("wind","The air smells very moist from the sea.");
   no_exit_display = 1;

    add_listen("main","Thunder rumbles overhead as the sea storm builds.");
	 add_listen("wind","You hear the breeze whipping through the grasslands.");

    set_chance(10);
    add_msg("You hear waves crashing into the shore in the distance.");
	 add_msg("You hear a whistling noise as the winds whip through the grasslands.");
	 add_msg("Thunder "+BOLD+"rumbles"+NORM+" overhead menacingly...");
	
    add_exit("/players/reflex/realms/coastline/plains4","west");
    add_exit("/players/reflex/realms/coastline/mount_ents1","east");
    add_exit("/players/reflex/realms/coastline/plains2","south");
    add_exit("/players/reflex/realms/coastline/plains3","southwest");         
    set_light(1);
    }
