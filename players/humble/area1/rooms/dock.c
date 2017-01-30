 /* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIW+"Loading Dock"+NORM;
    long_desc =
    "You have stepped foot on the loading dock.  This is where\n"+
    "loads are unloaded from the truck and brought to the\n"+
    "backroom.  This is also where the employees smoke\n"+
    "their cancer sticks.  The loading dock is empty right now.\n"+
    "You can see a beautiful view of the parking lot from here.\n"+
    "There is nothing of great interest here.\n";

    items =
    ({
    "dock","Well shit bra, the loading dock is empty",
    "parking lot","The parking lot looks very nice from here",
    "lot","The parking lot looks very nice from here",
    });
    dest_dir =
    ({
    RPATH+"backroom",        "back",
    });

    move_object(clone_object("players/humble/area1/mobs/beth.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/bonnie.c"), this_object());
  }
}
