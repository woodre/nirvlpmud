/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code*/

#include "/players/humble/area1/defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = "A parking lot";
    long_desc =
    "You have fallen into a crowded grocery store parking lot.\n"+
    "The lot is stuffed with rows of SUVs, trucks and rice-burners.\n"+
    "A car zooms by you as you survey the area. Dozens of people\n"+
    "are walking around the parking lot, some are employess of the grocery store.\n"+
    "On top of the store is a sign that reads: "+HIY+" Q F C "+NORM+" .\n"+
    "Not too far from you there are automatic sliding glass doors you could enter.\n";

    items =
    ({
    "car",
    "there are many cars crowding the parking lot",
    "store",
    "In front of you is a "+HIY+"Q F C"+NORM+" store, try entering it",
    "clerk",
    "There is a courtesy clerk here who doesn't look like he's having much fun",
    });
    dest_dir =
    ({
    "/players/humble/area1/rooms/checkstand1.c",        "enter store",
    "/players/humble/area1/rooms/entrance.c",        "back"
    });
  }
}

init() {
    ::init();
    add_action("enter","enter");
}


enter(arg) {

    if (!arg || arg == "") {
        notify_fail("What are you trying to enter?\n");
        return 0;
    }

    if (arg == "gateway") {
        write("You return to where you came from.\n");
        say(capitalize(this_player()->query_name())+" returns to the Gateway.\n");
        move_object(this_player(),"/players/humble/area1/rooms/entrance.c");
        return 1;
    }

    if (arg == "store") {
        write("The automatic doors slide open and you enter the store.\n");
        say(capitalize(this_player()->query_name())+" steps inside the store.\n");
        move_object(this_player(),"/players/humble/area1/rooms/checkstand1.c");
        return 1;
    }

    notify_fail("You can only enter the 'store' or the 'gateway' from here.\n");
    return 0;
}
