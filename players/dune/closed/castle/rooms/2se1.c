inherit "room/room";
#include "definitions.h"

void init() {
        add_action("smell","smell");
::init();
}

reset(arg) {
        if(!arg) {
        set_light(1);
        short_desc="Low ground path";
        long_desc=
"     To your dismay, almost all of the higher land patches you have\n"+
"hoped to walk on are gone.  The land is generally lower here, and you\n"+
"find yourself occassionally having to get your feet muddy and wet.\n"+
"The mud here has a strong pine scent.  The swamp here must be quite old.\n"+
"You can smell the age, it is everpresent in the air.\n";

   dest_dir=({
        CASTLEROOM+"/sroad1.c","northwest"  ,
        CASTLEROOM+"/2south1.c","south"  ,
        CASTLEROOM+"/2east.c","east"  ,
        CASTLEROOM+"/2sse1.c","southeast"  ,
            });

   items=({
        "mud","The mud has caked your lower clothes thickly",
   });
   }   }

int smell(string str) {
        write("You take in the smells of the swamp air.\n");
        return 1;
}
