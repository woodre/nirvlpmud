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
    set_light(0);
    short_desc = "Maintenance Hallway";
    long_desc =
    "  A Maintenance Hallway\n\
This hallways connects the maintenance shaft with the \n\
underworks of the spaceport. The automation of the \n\
spaceport eliminated the need for any kind of human \n\
intervention at this level. The walls here are dry and \n\
the air is warming up.\n ";

items = ({
    "shaft",
    "A tall, square tube that connects the maintenance level to the concourse level",
    "spaceport",
    "The Nirvana Universal Transport Spaceport is a living structure that continues to develop new corners to explore",
    "walls",
    "The walls here are not we like at the base of the shaft"
});

dest_dir = ({
    SPROOM+"under1.c","northwest",
    SPROOM+"under3.c","southeast"
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
