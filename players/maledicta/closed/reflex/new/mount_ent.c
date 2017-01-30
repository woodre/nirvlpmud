#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg){
   if(arg) return;
    set_short("Between two cliffs and a hard place");
    set_long(
        "You are at the western end of a pass, standing between hills\n"+
	"to the west and north.  You can go south between the hills or\n"+
	"east into a mountain pass from here.  The wind screams into\n"+
	"the pass to the east, and overhead dark clouds pour down rain\n"+
	"on everything.\n");
   add_item("path","This is a muddy path leading south and east.");
   add_item("hill","There is a hill to the west blocking your path.");
   add_item("pass","The pass leads off to the west.");
   add_item("clouds","Lightning streaks the sky as the clouds poor rain on you.");
   no_exit_display = 1;
   add_smell("main","You detect the slight smell of ozone in the salty sea air.");
	add_smell("wind","The air smells very moist from the rain.");
   add_listen("main","You hear a screaming noise as the winds whip through the pass.");
	add_listen("wind","Thunder crashes overhead.");
	
   set_chance(10);
   
	add_msg("Thunder rumbles overhead.");
	add_msg("The wind howls through the mountains.");
	add_msg("Lightning "+BOLD+YEL+"strikes"+NORM+" above!");

   add_exit("/players/reflex/realms/coastline/mount_ents1","south");
	add_exit("/players/reflex/realms/coastline/pass","east");

   set_light(1);
   }



  
