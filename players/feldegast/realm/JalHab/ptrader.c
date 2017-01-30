#include "defs.h"

inherit "/players/feldegast/std/generic_shop.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("tully")) 
    move_object(clone_object(MON_PATH+"dtrader.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Dwarven Trading Post";
  long_desc=
"  The dwarven trading post is wide and short, the ceiling rising to\n\
six feet at its highest.  Various trading goods are neatly stacked,\n\
placed on shelves, or hung from rafters.  A pair of short but comfy\n\
chairs are placed in front of an odd contraption by an open window.\n\
Commands: list, buy, sell, value\n";
  items=({
    "contraption","It appears to be a steam operated fan, designed to propel\n"+
                  "cool air at the occupants of the two seats.  Unfortunately,\n"+
                  "the engine makes more heat than the fan pushes away",
  });
  dest_dir=({
    PATH+"pwell.c","southeast",
  });
  move_object(clone_object(OBJ_PATH+"vase.c"),storage);
  move_object(clone_object(OBJ_PATH+"watch.c"),storage);
  move_object(clone_object(OBJ_PATH+"statue.c"),storage);
  move_object(clone_object(OBJ_PATH+"lamp.c"),storage);
  move_object(clone_object(OBJ_PATH+"8-ball.c"),storage);
  move_object(clone_object(ARM_PATH+"dwarf_plate.c"),storage);
}
