/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "This is another set of checkstands. The checkers here are\n"+
    "just as worthless as the checkers before.  To the east is\n"+
    "the "+HIB+"Bakery"+NORM+" .  Past the checkstands is aisle 10.\n"+
    "West is another set of checkstands.  To the north is the aisle carrying\n"+
    " the canned goods\n";

    items =
    ({
    "bakery",
    "To the east is the "+HIB+"Bakery"+NORM+" where the sweet stuff is at.",
    "aisle",
    "This aisle contains the canned goods. Oh yeah!",
    "checkstand",
    "This is a checkstand busy with customers yammering about important things they"+
    "  read about in the morning newspaper",
    "important things they read in the morning newspaper",
    });
    dest_dir =
    ({
    RPATH+"checkstand2",        "west",
    RPATH+"aisle10",        "north",
    RPATH+"bakery",        "east",
    });

    move_object(clone_object("players/humble/area1/mobs/customer13.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer14.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/roni.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/coleen.c"), this_object());
  }
}

