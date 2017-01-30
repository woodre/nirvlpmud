/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code*/

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = "A parking lot";
    long_desc =
    "You have fallen into a crowded grocery store parking lot.\n"+
    "The lot is stuffed with rows of SUVs, trucks and rice-\n"+
    "burners.  A car zooms by you as you survey the strange\n"+
    "surroundings.  Dozens of people are walking around the\n"+
    "parking lot.  Some are employees of the grocery store.\n"+
    "On the top of the store is a sign that reads: "+HIY+" Q F C "+NORM+" .\n"+
    "Not too far from where you stand there are automatic\n"+
    "sliding glass doors that you could enter if you wish.\n";

    items =
    ({
    "car",
    "There are many cars crowding the parking lot",
    "store",
    "In front of you is a "+HIY+"Q F C"+NORM+" store, try entering it",
    "doors",
    "Automatic sliding glass doors leading into the "+HIY+"store"+NORM+" that you could enter",
    "lot",
    "Looking around you are stunned by one of the biggest idiots you've"+
    " ever seen standing in front of you...."+
    "wait that's your reflection in a window",
    });
    dest_dir =
    ({
    RPATH+"entrance",        "back"
    });

    move_object(clone_object("players/humble/area1/mobs/customer15.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/justin.c"), this_object());
  }
}

    init() {
    ::init();
    add_action("enter","enter");
}

    enter(arg) {

    if(!arg || arg == "") {
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

    notify_fail("What are you trying to enter?\n");

    return 0;
}
