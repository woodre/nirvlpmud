#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg){

  if(arg) return;
    set_short("Entrance to the plains");
    set_long(
        "The path widens here, opening up onto a plain to the west,\n"+
	"while north it leads back into the mountains.  East and south\n"+
	"are blocked by steep hills, and far off to the west you hear\n"+
	"the distant sound of waves crashing into a shoreline.  The storm\n"+
	"overhead is very intense, and your standing ankle deep in mud.\n");

   no_exit_display = 1;
    add_item("path","This is a muddy path leading north and west.");
    add_item("plains","Wide open plains lead out to the west.");
    add_item("pass","The pass leads off to the west.");
    add_item("storm","Lightning streaks the sky as the clouds poor rain on you.");

    add_smell("main","You detect the slight smell of ozone in the salty sea air.");
	 add_smell("wind","The air smells very moist from the rain.");
    
    add_listen("main","You hear a screaming noise as the winds whip through the pass.");
	 add_listen("wind","Thunder crashes overhead.");

    set_chance(10);
    add_msg("Thunder rumbles overhead.");
	 add_msg("The wind howls through the mountains.");
	 add_msg("Lightning "+BOLD+YEL+"strikes"+NORM+" above!");

    add_exit("/players/reflex/realms/coastline/plains1","west");
    add_exit("/players/reflex/realms/coastline/mount_ent","north");

    set_light(1);
}


