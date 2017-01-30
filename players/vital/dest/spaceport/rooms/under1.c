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
int x;

reset(arg) {
    x = 1;
    if(!arg) { 
    set_light(0);
    short_desc = "Maintenance Room";
    long_desc =
    "  The Maintenance Rooms\n\
This room is damp and every surface glistens with a wet sheen. \n\
Water is leaking in from somewhere and resulting in the slow \n\
degredation of the area. There is a ladder that heads up through \n\
a shaft in the ceiling. This room has an opening that heads off \n\
to the southeast. The floor of the room is cluttered with an \n\
ancient collection of pipes, conduits, and other things.\n ";

items = ({
    "room",
    long_desc,
    "surface",
    "There is water covering nearly every surface here. There is dampness and mildew, covered in the film of the water covering everything",
    "sheen",
    "The reflection of light is returned from most surfaces",
    "water",
    "There is moisture here that comes from somewhere else. Obviously it shouldn't be here. Someone did not plan for this contingency",
    "area",
    "This area has been abandoned for a long time",
    "ladder",
    "The ladder provides a way to leave the room. You may \'ascend\' the ladder to head out of the room",
    "shaft",
    "The vertical opening heads straight up from the northwest corner of the room",
    "ceiling",
    "The ceiling is slightly less moist than the rest of the room, and it is punctuated by the maintenance shaft heading up",
    "opening",
    "There is a tunnel that heads off toward the southeast",
    "floor",
    "There are pieces of piping, old conduits, grates, tools, and other things",
    "pipes",
    "These pipes were once used in the construction of this spaceport",
    "conduits",
    "These sections of small piping is used to run protected wiring through",
    "things",
    "These are miscellaneous objects that are too numerous to determine between"
});

dest_dir = ({
    SPROOM+"under2.c","southeast",
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_up","ascend");
}

search_me(str) {
    object conduit;
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    switch(str) {
        case "floor":
            write("You rumage through the miscellaneous pieces on the floor, but come up empty handed.\n");
            break;
        case "pipes":
            write("You find a pipe that is loose in the pile and it rolls over on your foot.\n");
            TP->hit_player(5+random(5));
            break;
        case "conduits":
            if(x) {
            write("This piece of electrical conduit might possibly be used as a weapon.\n");
            conduit = CO("/obj/weapon.c");
            conduit->set_id("conduit");
            conduit->set_name("electrical conduit");
            conduit->set_alias("conduit");
            conduit->set_short(YEL+"Electrical Conduit"+NORM);
            conduit->set_class(10);
            conduit->set_weight(4);
            conduit->set_long("  This long piece of electrical conduit has \
been discarded \nfrom the excess of stuff that was used to construct the \
N.U.T.S. You \nhold a piece of what could have been part of the spaceport.\n");
            conduit->set_info("What a useless piece of junk.\n");
            MO(conduit, TO);
            x = 0;
            return 1;
            }
            write("You sort through the conduiting and find that it's nothing you would want.\n");
            break;
        case "things":
            write("You find a small grate in the wall that was covered by the piles of stuff. The grate looks like it might be \'shift\'ed.\n");
            add_action("move_grate","shift");
            break;            
        default : write("You furiously search the "+str+" but find nothing.\n");
    }
    return 1;
}

move_up() {
    TP->move_player("up the ladder#"+SPROOM+"shaft2.c");
	return 1;
}

move_grate(str) {
    if(!str) {
        notify_fail("What are you trying to shift?\n");
        return 0;
    }
    if(str == "grate") {
        write("You move the small grate slightly, and it falls to the floor. There is a passageway behind the grate that leads off toward the northwest. Perhaps you can \'enter\' the passage.\n");
        add_action("move_sewer","enter");
        return 1;
    }
    write("You cannot shift that.\n");
    return 1;
}

move_sewer(str) {
    if(!str) {
        notify_fail("What are you trying to enter?\n");
        return 0;
    }
    if(str == "passage" || str == "grate") {
        write("You squeeze your shoulders first into the passage and pull your legs in behind you.\n");
        TP->move_player("wriggling through the grate#"+SPROOM+"sewer1.c");
        return 1;
    }
    write("What are you trying to enter, and are you sure that you can enter it?\n");
    return 1;
}
