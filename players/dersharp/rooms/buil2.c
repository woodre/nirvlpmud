inherit "room/room";
#include "ex.h"
int i;
reset(arg) {
        if(!present("student")) {
        for(i=0;i<7;i++) {
           move_object(clone_object(MONS + "student"),TOB);
        }
}
        if(!arg){
        set_light(1);
        short_desc="Classroom";
        long_desc="     You enter a large classroom with only around\n"+
                  "24 students in it.  In this section of the room is\n"+
                  "desks and chairs indicative of a classroom.\n";
        dest_dir=
        ({
                ROOMS + "buil1","west",
                ROOMS + "buil6","southwest",
                ROOMS + "buil7","south",
	});
	}
}
