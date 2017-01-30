/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIY+"Q F C"+NORM;
    long_desc =
    "This the frozen goods aisle.  There are all sorts of great\n"+
    "food down this aisle.  Frozen pizzas, frozen fruits and\n"+
    "vegetables.  Ice creams fill the front of this aisle.  There is\n"+
    "a woman filling the frozen section with goods.  A pallet of\n"+
    "frozen items blocks most of the aisle and many customers\n"+
    "are very upset.  Back west is the organic aisle, to the north is \n"+
    "the "+HIR+"Meat Department"+NORM+".  South are more\n"+
    "checkstands.  To the east is another aisle.\n";

    items =
    ({
    "meat department",
     "QFC's Meat Department",
    "ice cream",
    "Ben and Jerry's, Breyer's, Dreyer's, take your pick",
    "pallet",
    "A board of frozen stacked to the ceiling",
    "aisle",
    "It's freezing cold on this aisle, you should have brought a coat",
    "vegetables",
     "Frozen bags of broccoli, carrots, cauliflower, etc",
    "fruit",
    "There is a small section of frozen fruits here",
    "pizza",
    "It's not delivery, it's Digornio",
    });
    dest_dir =
    ({
    RPATH+"meat",        "north",
    RPATH+"aisle1",        "west",
    RPATH+"aisle10",        "east",
    RPATH+"checkstand2",         "south",
    });

    move_object(clone_object("players/humble/area1/mobs/todd.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/pavel.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer3.c"), this_object());
    move_object(clone_object("players/humble/area1/mobs/customer4.c"), this_object());
  }
}

