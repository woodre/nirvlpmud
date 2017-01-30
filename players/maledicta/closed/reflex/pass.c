#include "/players/reflex/lib/include/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg){
int blah;
  if(!present("templar_guard", this_object())){
    for(blah = 0; blah < 2; blah++){
    move_object(clone_object("/players/maledicta/cont/war/templar_guard.c"), this_object());
    }
   }

    if(arg) return;
    set_short("Inside the coastal pass");
    set_long(
        "Rocky cliffs reach high above you on either side, dwarfing anything\n"+
	"between them.  As you walk through you can't help but notice the\n"+
	"total lack of life between these natural walls.  There are muddy\n"+
	"bootprints on the canyon floor, and the sheer cliffs speak to the\n"+
	"power of the wind and water that have shaped them.  The pass goes\n"+
	"both east and west.\n");
    add_item("floor","This is a dusty path leading east and west."); 
    add_item("mountains","You are between two towering cliffs carved into"+
             " mountainsides to the\nnorth and south.");
    add_item("pass","You are in the pass, it goes east and west.");
    add_item("bootprints",
             "Muddy bootprints betray the presence of a large number of men nearby...");
    add_item(({"cliffs","walls"}),
        "The cliffs tower far above your head to the north and south.");

    add_smell("main","You detect the slight smell of ozone in the salty sea air.");
	 add_smell("wind","It smells like rain is coming...");
	
    add_listen("main","You hear a screaming noise as the winds whip through the pass.");
	 add_listen("wind","You hear thunder in the distance to the west.");
 
    set_chance(10);
    add_msg("Thunder rumbles in the distance.");
	 add_msg("The wind screams through the pass, drowning out everything else.");
	 add_msg("Lightning "+BOLD+YEL+"strikes"+NORM+" in the distance...\n");

    add_exit("/players/reflex/realms/coastline/mount_ent","west");
	 add_exit("/players/reflex/realms/coastline/pass_ent","east");
    set_light(1);
    }


