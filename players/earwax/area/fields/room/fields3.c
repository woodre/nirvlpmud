#include "../defs.h"

inherit ROOM;
inherit LAND;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("A grassy field extends from here west as far as the eye can see.  To the east is a cliff marking the boundary of this valley, to the north and south are more fields.  A building can also be seen to the south, and a castle far in the distance to the north and northwest.");
  add_exit("south",RPATH+"by_shack");
  add_exit("west", RPATH+"fields2");
  add_exit("north", RPATH+"fields4");
  add_desc("grass", "It's thick and luxuriant.");
  add_desc("field", "This field extends far to the north, south, and west, and is broken only by the cliff to the east.");
  add_desc("cliff", "It rises high and straight, and marks the eastern boundary of this area.");
  add_desc("boundary", "Earwax has to set boundaries to his area somehow.");
  add_desc("castle", "You can't make out many details at this distance, but it looks huge.");
  add_desc("building", "There is a stone building a short distance to the south of here.");
  add_desc("valley", "You are in a large valley in a mountain range.");
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_lot_size(3);
  set_cost(150000);
  set_realm_name("Fields");
  setup_land();
}
