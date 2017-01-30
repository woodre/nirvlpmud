#include "../defs.h"

inherit LAND;
inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("Grassy fields extend to the north and east.  The south and west ends of this field are marked by majestic mountains.  Far in the distance to the north, a castle can be seen.");
  add_exit("east", RPATH+"fields7");
  add_exit("north", RPATH+"fields9");
  add_desc("castle", "It's much too far away to make out any details.");
  add_desc("mountains", "They rise from here as far as you can see.");
  add_desc("fields", "The fields are covered in thick, lush grass.");
  add_desc("grass", "It's thick and lush.");
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_realm_name("Fields");
  set_lot_size(9);
  set_cost(450000);
  setup_land();
}
