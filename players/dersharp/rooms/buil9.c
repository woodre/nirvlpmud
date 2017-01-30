inherit "room/room";
#include "ex.h"
int i;
reset(arg) {
        if(!present("assistant")) {
        for(i=0;i<2;i++) {
           move_object(clone_object(MONS + "assistant"),TOB);
	}
}
        if(!arg){
        set_light(1);
        short_desc="Office";
        long_desc="     You enter this room slowly, seeing two desks on\n"+
                  "either side of a large door to the west.  They are \n"+
                  "rather small yet they are holding a great bulk of \n"+
                  "papers.  As you look closer at the papers you see\n"+
                  "the famailiar red-ink of teaching assistants....\n"+
		  "\n";
        dest_dir=
        ({
		ROOMS + "buil8","west",
		ROOMS + "buil10","east",
	});
	}
}
init(){
        ::init();
        add_action("west","west");
        }
west() {
        if(present("assistant")){
        write("The assistants will not let you by!\n");
        return 1;
        }
        return 0;
        }
