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
    short_desc = "Maintenance Shaft";
    long_desc =
    "  A Maintenance Shaft\n\
This long shaft decends even farther into the darkness below \n\
the N.U.T.S. There are recesses here for lights, but this area \n\
was long ago forgotten and powered down. The ladder here is damp \n\
and rusty, and it is easy to tell that the area has not seen \n\
much use in recent history.\n ";

items = ({
    "shaft",
    "This long, narrow, square shaft descends beneath the depths of the \n\
N.U.T.S. complex",
    "recesses",
    "These small pockets once held lights to provide ease of movement in the shaft",
    "lights",
    "There used to be lights in this shaft, indicating a time of former use",
    "area",
    "The rooms here are old and foundational to the rest of the spaceport",
    "ladder",
    "The metal ladder has not aged well, and is slippery and rusting. \n\
It provides two ways to move in the shaft. You can either \n\
\'ascend\' or \'descend\' the ladder",
    "rust",
    "The corrosion of the metal is indicative of the lack of care and \n\
concern for this area",
    "history",
    "Heh, wouldn't it be nice if you could see all of history"
});

dest_dir = ({
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_up","ascend");
    add_action("move_down","descend");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    switch(str) {
        case "lights":
        case "recesses":
            write("You find nothing but empty light sockets and a sharp jolt of pain.\n");
            TP->hit_player(10+random(5));
            break;
        case "shaft":
        case "area":
            write("You find the ladder, the light recesses, and rust.\n");
            break;
        default : write("You furiously search the "+str+" but find nothing.\n");
    }
    return 1;
}

move_up() {
    TP->move_player("up the ladder#"+SPROOM+"shaft1.c");
	return 1;
}

move_down() {
    TP->move_player("into the depths#"+SPROOM+"under1.c");
	return 1;
}
