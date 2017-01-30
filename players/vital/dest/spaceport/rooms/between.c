/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    3/6/01            */
/*    Modified:   3/6/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "room/room";
object mob;

reset(arg) {
    if(!present("controller")) {
        mob = CO(SPNPC+"controller.c");
        MO(mob, TO);
    }
    if(!arg) { 
    set_light(-1);
    short_desc = "Between";
    long_desc =
    "  The In Between Area\n\
This area is crowded in between the massive hydraulic pistons, \n\
the wires, computer equipment and other hardware. This claustraphobic \n\
little space crowds out the light. The wires form a curtain around \n\
the edges of the space and the constant movement spins you around \n\
so that all the directions are confused.\n ";

items = ({
    "piston",
    "These massive, hydraulic cylinders are used to absorb the shock of \n\
shuttles and landings",
    "equipment",
    "The complex computers have run attended for years, monitoring the \n\
landing pads and the pistons",
    "pads",
    "The composite material that makes up the landing pads breaks down \n\
over time, but the pistons help prolong the life by absorbing \n\
some of the pressures",
    "hardware",
    "The hardware helps to keep the spaceport running smoothly",
    "space",
    "Everything presses in around you, making a small space seem very tiny",
    "light",
    "The light is kept out by the wires",
    "wires",
    "The wires are a veil of darkness, blocking out the light",
    "curtain",
    "The wires are a veil of darkness, blocking out the light",
    "directions",
    "You are not sure which direction you came from, or which direction \n\
is \'out\'\n"
});

dest_dir = ({
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_out","out");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}

move_out() {
    string dest;
    dest = "";
    switch(random(4)) {
        case 0:
            dest = "under4.c";
            break;
        case 1:
            dest = "under5.c";
            break;
        case 2:
            dest = "under6.c";
            break;
        case 3:
            dest = "under7.c";
            break;
    }
    TP->move_player("out of this place#"+SPROOM+dest);
    return 1;
}
