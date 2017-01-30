/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIC+"Seafood Department"+NORM;
    long_desc =
    "This is QFC's "+HIC+"Seafood Department"+NORM+" . There is a horrible\n"+
    "smell emanating from the very spot you stand.  There is a large\n"+
    "drain in the middle of the floor.  Two salmon are lined up\n"+
    "facing each other on top of ice.  There is shrimp\n"+
    "and crab avaliable to buy.  Of to the corner of the\n"+
    "department is a tank which carries live lobsters.\n";

    items =
    ({
    "crab",
    "There is a crab here, he's dead of course",
    "shrimp",
    "There are little shrimpies and large Tiger shrimp here",
    "tank",
    "There are lobsters here with rubberbands covering their pinchers.  They are"+
    "     fighting one another by boxing, amazing species......",
    "drain",
    "A drain, perhaps you could "+HIW+"remove"+NORM+" it",
    });
    dest_dir =
    ({
    RPATH+"aisle10",        "south",
    });

    move_object(clone_object("players/humble/area1/mobs/ryan.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/eric.c"), this_object());
  }
}
