#include "../defs.h"

inherit LAND;
inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("Grassy fields end to the south and west, where mountains rise upwards endlessly.  To the east lies a dirt road, and the fields continue to the north.");
  add_exit("east", RPATH+"road1");
  add_exit("north", RPATH+"fields7");
  add_desc("fields", "They extend to the north from here.  The grass covering them is thick and lush.");
  add_desc("grass", "It's thick.");
  add_desc("road", "You can see a dirt road east of here.");
  add_desc("mountains", "The mountains are steep, with the tops concealed by clouds.");
  add_desc("clouds", "The clouds all look like Q-Tips.");
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("corporal", this_object()) && random(100) <  CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_realm_name("Fields");
  set_cost(450000);
  set_lot_size(9);
  setup_land();
}
