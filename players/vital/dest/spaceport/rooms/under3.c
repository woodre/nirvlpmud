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
    short_desc = "Maintenance Hallway";
    long_desc =
    "  A Maintenance Hallway\n\
The hallway continues on around the corner up ahead. There \n\
is more light in this area, reflected from some source up \n\
ahead. The heat is definitely stronger a more present reality.\n\
The walls have pipes and conduits running along them in every \n\
direction.\n ";

items = ({
    "corner",
    "The hallway makes a turn to the south",
    "light",
    "It is brighter here than it was near the maintenance shaft",
    "walls",
    "The walls are laces with criss-crossing pipes and conduits",
    "pipes",
    "The pipes carry some type of fluid",
    "conduits",
    "The conduits are used to protect electrical wiring"
});

dest_dir = ({
    SPROOM+"under2.c","northwest",
    SPROOM+"under4.c","south"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}
