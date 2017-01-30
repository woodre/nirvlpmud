inherit "room/room";
#include "ex.h"
int i;
reset(arg){
	if(!present("professor")){
        move_object(clone_object(MONS + "prof"),TOB);
	}
	if(!present("student")){
        move_object(clone_object(MONS + "gstudent"),TOB);
	}
	if(!arg){
	set_light(1);
	short_desc="Professors Office";
	long_desc="	This is a carbon-copy of all the other offices\n"+
		  "in the building.  There is a window in the wall\n"+
		  "letting in the air from outside.\n";
	dest_dir=
	({
		"players/dersharp/rooms/buil4.c","east",
		"players/dersharp/rooms/buil8.c","south",
	});
}
}
