    /* COPYRIGHT (C) VITAL CORP,  outline derived from Vital Code */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = GRN+"Deli"+NORM;
    long_desc =
    "This is the "+GRN+"Deli"+NORM+" .  There are lots of fresh lunch\n"+
    "meats kept here.  Also there is a variety of potato salads, chicken\n"+
"strips, jo-jos and other various Deli items. Behind the\n"+
    "counter is a meat slicer as well as a weighted electronic\n"+
    "scale to price items by their weight.  To the south is the aisle\n"+
    "you came from.\n";

    items =
    ({
    "chicken strips",
    "Those are some dry ass chicken strips, gross",
    "meat slicer",
    "A slicer used to cut turkey, ham, roast beefs and other varieties of meats",
    "scale",
    "No it won't weigh out your ounces and QPs of illicit drugs",
    "aisle",
    "The aisle with all that organic stuff, ewww",
    });
    dest_dir =
    ({
    RPATH+"aisle1",        "south",
    });

    move_object(clone_object("players/humble/area1/mobs/sue.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/pam.c"), this_object());
  }
}
