#include "../defs.h"

inherit ROOM;
inherit LAND;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("A grassy field extends in all directions.  To the west a dirt road can be seen, and far off in the distance to the north is a castle.  To the southeast a short distance away lies a stone building.");
  add_exit("north", RPATH+"fields5");
  add_exit("west", RPATH+"road2");
  add_exit("east", RPATH+"fields3");
  add_exit("south", RPATH+"fields1");
  add_desc("field", "Thick, luxuriant grass fields surround you.");
  add_desc("grass", "It's thick.");
  add_desc("road", "It looks to be a fairly wide dirt road.");
  add_desc("castle", "It's too far to make out many details.");
  add_desc("building", "A stone building lies to the southeast.");
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_realm_name("Fields");
  set_cost(350000);
  set_lot_size(6);
  setup_land();
}
