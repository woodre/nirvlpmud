/* COPYRIGHT (C) VITAL CORP,  Outline derived from Vital Code*/

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "You have stepped foot into your local Quality Food Center.\n"+
    "in front you is an aisle containing dry, chilled an\n"+
    "frozen goods.  There are checkers busy at work here\n"+
    "chatting with happy customers as courtesy clerks bag\n"+
    "groceries.  To the east are more checkstands.  To\n"+
    "west is the "+HIM+"Floral"+NORM+" department.\n";

    items =
    ({
    "aisle",
    "There are clerks working down the aisle throwing freight\n"+
    "as customers shop carefully",
    "floral",
    "To the west is the floral department, there are all sorts of basic\n"+
    "roses and flowers ready for you to purchase",
    "checkstand",
    "Here is a row of three checkstands with whiny checkers",
    });
    dest_dir =
    ({
    RPATH+"floral",        "west",
    RPATH+"aisle1",        "north",
    RPATH+"checkstand2",        "east",
    RPATH+"lot",        "out"
    });

    move_object(clone_object("players/humble/area1/mobs/customer9.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer10.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/kathy.c"), this_object());
  }
}
