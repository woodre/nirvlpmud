/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIW+"Freezer"+NORM;
    long_desc =
    "This is the store's freezer.  It's extremely cold in here and you\n"+
    "don't think you could survive long in here without a coat.\n"+
    "There are racks here filledwith ice cream, boxes of pizza\n"+
    "and other random frozen goods.  There are milk crates here\n"+
    "filled with random frozen goods.  Two pallets stacked to the\n"+
    "ceiling lay in the dead center of the floor.  Off to the corner of\n"+
    "the freezer you hear something stirring.\n";

    items =
    ({
    "pallets","Pallets stacked to the ceiling with frozen backstock",
    "pallet","A pallet stacked to the ceiling with frozen backstock",
    "Ice cream","Breyers, Dreyers, Tilamook, the rows are never ending",
    "ice cream","Breyers, Dreyers, Tilamook, the rows are never ending",
    "racks","Racks carrying vendor products such as ice cream and pizza",
    "crates","Milk crates filled with product",
    "milk crates","Milk crates filled with product",
    "freezer","Well it's probably 30 below, and it's frozen, not to mention cold",
    "pizza","Frozen pizzas. like digornio",
    });
    dest_dir =
    ({
    RPATH+"backroom",        "out",
    });

    move_object(clone_object("players/humble/area1/mobs/snowman.c"), this_object());
  }
}
