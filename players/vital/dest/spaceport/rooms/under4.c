/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    3/5/01            */
/*    Modified:   3/6/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "Maintenance Room";
    long_desc =
    "  The Maintenance Room\n\
This room is one of the great landing pad piston leveling \n\
rooms. There are massive, hydraulic pistons that keep the \n\
landing pads from fluctuating much either up or down. The \n\
sensitive computer equipment monitors the pressure created \n\
by the shuttles and their take offs and landings. The \n\
complex equipment creates many twists and turns.\n ";

items = ({
    "piston",
    "These massive, hydraulic cylinders are used to absorb the shock of shuttles and landings",
    "pistons",
    "These massive, hydraulic cylinders are used to absorb the shock of shuttles and landings",
    "equipment",
    "The complex computers have run attended for years, monitoring the landing pads and the pistons",
    "pads",
    "The composite material that makes up the landing pads breaks down over time, but the pistons help prolong the life by absorbing some of the pressures",
    "twists",
    "Your eyes get tired trying to follow where the pieces go",
    "turns",
    "The wiring winds in, out and around the pistons"
});

dest_dir = ({
    SPROOM+"under5.c","east",
    SPROOM+"under6.c","southeast",
    SPROOM+"under7.c","south",
    SPROOM+"under3.c","north"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_inbetween","squeeze");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    switch(str) {
        case "piston":
            write("You find a small place between the pistons.\n");
            break;
        case "place":
            write("There is a small area in between the equipment that you could \'squeeze\' into.\n");
            break;
        case "equipment":
            write("There is nothing to find in the equipment.\n");
            break;
        default: write("You furiously search the "+str+" but find nothing.\n");
    }
    return 1;
}

move_inbetween(str) {
    if(!str) {
        notify_fail("What are you trying to squeeze into?\n");
        return 0;
    }
    TP->move_player("in between#"+SPROOM+"between.c");
    return 1;
}
