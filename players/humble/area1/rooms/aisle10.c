/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "This is aisle 10, the canned foods aisle.  There is a helper\n"+
    "clerk here throwing freight onto the shelf.  The entire aisle is\n"+
    "perfectly faced, that is, all of the products are brought to the\n"+
    "very front of the shelf, it looks amazing.  Canned soup, fruits\n"+
    "vegetables, baked beans, all sort of canned goods line the\n"+
    "aisle. To the north is the "+HIC+"Seafood Department"+NORM+" .\n"+
    "To the east is the last aisle in the store which contains the dairy\n"+
    "section.  To the south is a set of checkstands, west is another aisle.\n";

    items =
    ({
    "aisle",
    "This is the canned goods aisle",
    "shelf",
    "A long row of shelfs, spaced about 1 foot from the next from bottom to top",
    "seafood department",
    "Your local QFC's Seafood Department doesn't smell so good",
    "soup",
    "One particular can of soup sticks out from the shelf",
    "can",
    "One particular can of soup sticks out from the shelf",
    });
    dest_dir =
    ({
    RPATH+"seafood",        "north",
    RPATH+"checkstand3",        "south",
    RPATH+"aisle12",        "east",
    RPATH+"aisle5",        "west",
    });

    move_object(clone_object("players/humble/area1/mobs/tyler.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer5.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer6.c"), this_object());
    }
}
