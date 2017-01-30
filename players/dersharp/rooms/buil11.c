inherit "room/room";
#include "ex.h"
int i;
reset(arg) {
        if(!present("prosper")) {
           move_object(clone_object(MONS + "prosper"),TOB);
	}
        if(!arg){
        set_light(1);
        short_desc="Office";
        long_desc="	This office seems to be slightly different than\n"+
		  "all the others.  It is smaller, yet it has more stuff\n"+
		  "in it.  You realize that this is a converted closet.\n"+
		  "\n";
	dest_dir=
	({
		ROOMS + "buil12","east",
	});
	}
}
