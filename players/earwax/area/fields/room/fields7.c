#include "../defs.h"

inherit LAND;
inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("Grassy fields extend in all directions from here.  Far off in the distance to the north stands a castle and to the east a dirt road can be seen.");
  add_exit("west", RPATH+"fields10");
  add_exit("east", RPATH+"road2");
  add_exit("north", RPATH+"fields8");
  add_exit("south", RPATH+"fields6");
  add_desc("fields", "They are covered in thick, lush grass.");
  add_desc("castle", "You can't make out many details at this distance.");
  add_desc("road", "A dirt road lies a short distance to the east.");
  add_desc("grass", "It's thick and lush.");
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_lot_size(9);
  set_cost(450000);
  set_realm_name("Fields");
  setup_land();
}
