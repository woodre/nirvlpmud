/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   3/5/01            */
/*    Realm:      Spaceport/Derelia */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "Backalley";
    long_desc =
"  The area here behind the bar is surrounded by businesses \n\
and homes on every side. Even in this forgotten area, the \n\
ground is fairly clean and the trash has all been stored \n\
in the proper receptacles. Near one of the trash receptacles \n\
is a rainwater grate.  A huge white building can be seen in \n\
the center of the town, dominating the view to the west.\n ";

items = ({
    "building",
    "The tallest building in the town, it is made of steel and white \n\
stone. Several pane glass windows can be seen along its surface",
    "bar",
    "The "+HIM+"Careful Wanderer"+NORM+" sits just behind you",
    "grate",
    "A small, 50 centimeter, metal grate lies recessed into the ground",
    "businesses",
    "Places like the "+HIM+"Careful Wanderer"+NORM+" other \n\
miscellaneous shops",
    "homes",
    "Some people have moved here and now call Derellia home",
    "area",
    "This backalley separates several buildings on every side",
    "ground",
    "The ground is clean and trash free",
    "trash",
    "The bar generates used barrels, dirty napkins, and a lot \n\
of broken glassware",
    "receptacles",
    "These large bins are the proper place for trash",
    "west",
    "You can see a large building to the west" 
});

dest_dir = ({
    "/players/maledicta/town/rooms/t9.c","back",
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("move_grate","move");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    if(str == "grate") {
        write("You find that the grate can be moved.\n");
        return 1;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

move_grate(str) {
    if(!str) {
        notify_fail("What is it you are trying to move?\n");
        return 0;
    }
    if(str == "grate") {
        write("You slide the grate up and out of it's recess in the floor.\n");
        write("The grate covered a hole that you can enter.\n");
        add_action("enter_hole","enter");
    }
    return 1;
}

enter_hole(str) {
    if(!str) {
        notify_fail("What is it that you are trying to enter?\n");
        return 0;
    }
    if(str == "hole") {
        TP->move_player("down into the hold#"+SPROOM+"dryroom.c");
        return 1;
    }
    write("You cannot enter that.\n");
    return 1;
}
