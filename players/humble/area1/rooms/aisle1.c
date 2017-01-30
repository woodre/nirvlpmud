/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "This is the Aisle 1.  The aisle is set up with numerous products.\n"+
   "This is the organic food Aisle. There is flaxseed, soy milk,\n"+
    "organic yogurt and bundles of organic wheat cereal found here.\n"+
    "North is the "+GRN+"Deli"+NORM+". To the east is Aisle 5, to the\n"+
    "south are the checkstands.\n";

    items =
    ({
    "deli",
    "This is your local QFC's Deli department",
    "yogurt",
    "Organic yogurt made with soy and all that miserable crap. YUCK!",
    "aisle",
    "You are standing on the organic foods aisle... everything here.... is fake",
    "soy milk",
    "This is a carton of soy milk, so disgusting you don't even need to refrigerate",
    "flaxseed",
    "Budday, I'd write you a better description but even I'm not sure what this shit is",
    "cereal",
    "A box of organic cereal, probably the only thing you could find yourself eating",
    });
    dest_dir =
    ({
    RPATH+"deli",        "north",
    RPATH+"checkstand1",        "south",
    RPATH+"aisle5",        "east",
    });
    move_object(clone_object("players/humble/area1/mobs/chris.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/alice.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer1.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer2.c"), this_object());
  }
}
