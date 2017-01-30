/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   3/5/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "Dry Room";
    long_desc =
"  This is a small room just below the surface of the ground. \n\
The light filters down from the grating overhead. The area \n\
hasn't seen much use in the last hundred years. From deep \n\
below you hear the rumbling of something horrid. On the wall \n\
to the north you notice something different.\n ";

items = ({
    "ground",
    "The ground forms the ceiling over your head in this underground cavern",
    "light",
    "There is not much light here in this subterranean chamber",
    "grating",
    "The grate overhead is about 50 centimeters square and made \n\
from some kind of metal",
    "area",
    "The depths of the underground certainly offer adventure",
    "wall",
    "It looks as though someone has scratched something on the wall. \n\
Perhaps you could \'read\' the scratchings",
    "scratchings",
    "It looks as though someone has scratched something on the wall. \n\
Perhaps you could \'read\' the scratchings",
    "below",
    "There is a small hole in the floor of this room that you could go down through"
});

dest_dir = ({
    SPROOM+"backalley.c","grate",
    SPROOM+"sewer5.c","down"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("read_me","read");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}

read_me(str) {
    if(!str) {
        notify_fail("What are you trying to read? (Try \'scratchings\'.)\n");
        return 0;
    }
    if(str == "scratchings") {
        write(pad("b E Wa Re\n", -25));
        write("ThE woRLd beLOW is NOt nicE\n");
        write(pad("I aLMosT dIEd!\n",-15));
        return 1;
    }
}
