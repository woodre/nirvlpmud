/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "As you walk along the checkstands dodging customers\n"+
    "your eyes glance up at all the pretty female checkers standing\n"+
    "in the checkstands.  As you listen into their conversations you\n"+
   "hear sob stories about their trouble filled lives and drunk\n"+
    "escapades.  Your eyes catch a stairwell leading upstairs\n"+
    "somewhere.  As you listen to the mindless chatter of\n"+
    "people within the store you have second thoughts\n"+
    "about venturing towards any other checkstands.\n"+
    "Perhaps a stroll down aisle 5?\n";

    items =
    ({
    "checkstand",
    "This is a lighted checkstand. It comes equipped with a"+
    "rotating belt to keep the groceries coming and an overly"+
    " dramatic checker",
    "stairwell",
    "A stairwell leading to the dreaded upstairs",
    "aisle",
    "An aisle containing frozen gorceries.  There is a woman throwing frozen goods"+
    "    into the freezer",
    });
    dest_dir =
    ({
    RPATH+"checkstand3",        "east",
    RPATH+"hall",        "up",
    RPATH+"aisle5",        "north",
    RPATH+"checkstand1",    "west",
    });

    move_object(clone_object("players/humble/area1/mobs/customer11.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer12.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/billy.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/randall.c"), this_object());
  }
}

init()
{
    ::init();
}
