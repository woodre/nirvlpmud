/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = BLU+"Dairy Cooler"+NORM;
    long_desc =
    "This is the "+BLU+"Dairy Cooler"+NORM+" .  It's about 35 degrees\n"+
    "inside this freaking thing.  There are cases of yogurt and\n"+
    "sour cream everywhere.  Milk crates stuffed with milk are\n"+
    "stacked all over the place.  It's best to leave Debbie's\n"+
    "stuff alone if ya know what's best.\n";

    items =
    ({
    "case",
    "Stacks of cases of all sorts of dairy goods are lying about everywhere",
    "yogurt",
    "Darigold, yoplait, tilamook, oh the choices",
    "sour cream",
    "Sour Cream, even more disgusting than mayonaise!",
    "crates",
    "Crates filled with cartons, plastic gallons and half gallons of milk, mooooo",
    });
    dest_dir =
    ({
    RPATH+"backroom",        "leave",
    });

    move_object(clone_object("players/humble/area1/mobs/wingedcow.c"), this_object());
  }
}
