/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "This is the aisle where all the dairy is contained.  There is a\n"+
    "pallet of dairy goods being stocked on this aisle.  To the west\n"+
    "is another aisle.  South is the "+HIB+"Bakery"+NORM+" . There is a set\n"+
    "of doors near the back of the aisle, perhaps you should sneak past\n"+
    "the help and enter them?\n";

    items =
    ({
    "doors",
    "Perhaps you could sneak past the help and enter them",
    "pallet",
    "A board of dairy goods stacked to the ceiling",
    "aisle",
    "You are on the aisle where the dairy goods are kept",
    "bakery",
    "To the south is the local bakery, mmmm bakery",
    });
    dest_dir =
    ({
    RPATH+"aisle10",        "west",
    RPATH+"bakery",         "south",
    });

    move_object(clone_object("players/humble/area1/mobs/customer7.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer8.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/jason.c"), this_object());
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

    if (arg == "doors") {
      write("You push the set of doors open and enter the backroom.\n");
      say(capitalize(this_player()->query_name())+" disappears into the backroom.\n"
);
      move_object(this_player(),"/players/humble/area1/rooms/backroom.c");
      return 1;
    }
}
