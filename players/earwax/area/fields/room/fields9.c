#include "../defs.h"

inherit LAND;
inherit ROOM;

void
on_create()
{
  set_color(HIG);
  set_short("A Grassy Field");
  set_no_clean(0);
  set_long("This is a large, grassy field that extends to the east and south.  To the north is a moat, beyond it, a castle.  To the west lie immense mountains.");
  add_exit("east", RPATH+"fields8");
  add_exit("south", RPATH+"fields10");
  add_desc("moat", "It's a vast moat that extends far to the east and west.  It's extremely murky, but you can still make out hordes of fish and less recognizable forms flitting about through it.");
  add_desc("fish", "Some are the size of sharks, others look related to pirahnas.  Whatever they are, they certainly don't look friendly.");
  add_desc("castle", "An immense castle lies beyond the moat.  Flags emblazoned with the standard of Earwax ("+FLAG+") fly from the towers at each corner, as well as from the two smaller towers near the drawbridge.");
  add_desc("mountains", "Immense mountains rise to the west, marking the western boundary of this valley.");
  add_desc("valley", "This is a large valley nestled within a mountain range.");
  add_desc("forms", "They look sinister.");;
  add_desc("field", "It's covered with thick grass.");
  add_desc("grass", "It's thick.");
  if (!present("private", this_object()) && random(100) < PVT) move_object((object)MOB_SETUP->make_pvt(), this_object());
  if (!present("corporal", this_object()) && random(100) < CPL) move_object((object)MOB_SETUP->make_pvt(), this_object());

  set_realm_name("Fields");
  set_lot_size(-2);
  set_cost(850000);
  setup_land();
}
