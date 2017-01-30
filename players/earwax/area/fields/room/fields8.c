#include "../defs.h"

inherit LAND;
inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_no_clean(0);
  set_short("A Grassy Field");
  set_long("A grassy field extends in all directions from here but north.  To the north is a moat the size of a small river, and beyond it stands a castle.  To the east a dirt road can be seen.");
  add_exit("west", RPATH+"fields9");
  add_exit("east", RPATH+"road3");
  add_exit("south", RPATH+"fields7");
  add_desc("moat", "It's a vast moat that extends far to the east and west.  It's extremely murky, but you can still make out hordes of fish and less recognizable forms flitting about through it.");
  add_desc("forms", "They look sinister.");
  add_desc("fish", "Some are the size of sharks, others look related to pirahnas.  Whatever they are, they certainly don't look friendly.");
  add_desc("castle", "An immense castle lies beyond the moat.  Flags emblazoned with the standard of Earwax ("+FLAG+") fly from the towers at each corner, as well as from the two smaller towers near the drawbridge.");
  add_desc("drawbridge", "It looks like it's raised right now.");
  add_desc("fields", "Grass-covered fields surround you.");
  add_desc("grass", "It's thick and lush.");
  add_desc("field", "You're standing on a grassy field.");
  add_desc("towers", "Tall, defensive, towers stand at the corners of the castle walls as well as to either side of the drawbridge.");
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_cost(800000);
  set_lot_size(-2);
  set_realm_name("Fields");
  setup_land();
}
