#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("soco");
  add_alias("comfort");
  add_alias("southern comfort");
  add_alias("bottle");
  set_short("A bottle of Southern Comfort");
  set_long("A tall bottle with clear glass, and a black and white label.");
  set_type("drinks");
  set_msg("You stop a moment to enjoy the smoothness and texture of the Southern Comfort\nas it warms your body.\n");
  add_cmd("drink");
  add_cmd("sip");
  add_cmd("swig");
  set_heal(35,35);
  set_charges(5);
  set_stuff(14);
  set_value(350);
}
