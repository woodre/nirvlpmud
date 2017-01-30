inherit "room/room";
#include "ex.h"
int i;
reset(arg){
        if(!present("professor")){
        move_object(clone_object(MONS + "prof"),TOB);
        }
        if(!arg){
        set_light(1);
        short_desc="Professors Office";
        long_desc="     This is a carbon-copy of all the other offices\n"+
                  "in the building.  There is a window in the wall\n"+
                  "letting in the air from outside.\n";
        dest_dir=
        ({
	ROOMS + "buil3","north",
	ROOMS + "buil9","east",
	});
	}
}
