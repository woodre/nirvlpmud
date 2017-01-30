#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";


reset(arg){
  if(arg) return;
    set_short("Entrance to a mountain pass");
    set_long(
        "Before you to the west stands a narrow pass between two\n"+
	"mountains leading to the coastline.  The path you are on\n"+
	"is slightly muddy here, and you can see the bootprints of\n"+
	"what must be many men tracked through the mud.  It is\n"+
	"raining lightly, and there is a horrible screeching sound\n"+
	"coming out of the pass from the wind, drowning out all other\n"+
	"sounds beyond.  There is a small path along the mountains\n"+
	"to the north and south, however it is blocked off by some\n"+
	"rockslides, eastward you can head back to the village, and\n"+
	"west leads through the pass.\n");
   no_exit_display = 1;
    add_item("path","This is a dusty path leading east and west."); 
    add_item("mountains",
             "This is a small mountain range blocking your path to the west.\n"+
             "You think you could pass it by the small opening between two hills\n"+
	          "directly westward.");
    add_item("pass",
             "There is a pass leading between the two mountains in front of you.\n"+
	          "It appears to be the only way to the coastline beyond..");
    add_item("sky",
             "The sky is overcast and you can feel the slightest drizzel in the\n"+
           	 "air around you.  It looks like rain is coming.");
    add_item("rockslides",
             "There are rockslides to the north and south, making the pass the\n"+
	          "only entrance to the coastline.");
 
   add_smell("main","You detect the slight smell of ozone in the salty sea air.");
	add_smell("wind","It smells like rain is coming..");

   add_listen("main","You hear a screaming noise as the winds whip through the pass.");
	add_listen("wind","You hear thunder in the distance to the west.");
   set_chance(10);
   add_msg("Thunder rumbles in the distance.");
	add_msg("The wind screams through the pass, drowning out everything else.");
	add_msg("Lightning "+BOLD+YEL+"strikes"+NORM+" in the distance...");
   add_exit("/players/reflex/realms/coastline/pass","west");
	add_exit("/players/reflex/realms/coastline/path","east");
   set_light(1);
   }


