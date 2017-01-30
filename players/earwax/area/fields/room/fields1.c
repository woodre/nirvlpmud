#include "../defs.h"

inherit LAND;
inherit ROOM;

object Monster1, Monster2;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("Grass-covered fields extend to the north from here.  To the west a dirt road can be seen, to the east lies a fairly large stone structure.  The southern edge of this field is cut off by the mountain range surrounding this valley.");
  add_exit("north", RPATH+"fields2");
  add_exit("east", RPATH+"by_shack");
  add_exit("west", RPATH+"road1");
  add_desc("grass", "It's thick.");
  add_desc("field", "It's a field covered in thick grass.");
  add_desc("fields", "It's a field covered in thick grass.");
  add_desc("road", "A dirt road to the west of here travels north.");
  add_desc("mountain range", "The mountains surrounding this valley are steep and unclimbable.");
  add_desc("mountains", "The mountains surrounding this valley are steep and unclimbable.");
  add_desc("range", "The mountains surrounding this valley are steep and unclimbable.");
  add_desc("valley", "This is a large valley nestled in a mountain range.");
  add_desc("building", "A fair-sized stone building stands to the east of here.");
  add_desc("structure", "A fair-sized stone building stands to the east of here.");
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("corporal", this_object()) && random(150) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());


  set_realm_name("Fields");
  set_lot_size(6);
  set_cost(300000);
  setup_land();
}

/*
  setup_land(this_object());
init() {
  ::init();
}

*/
