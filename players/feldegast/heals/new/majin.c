#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg)return;
  set_name("majin potion");
  add_alias("majin");
  add_alias("potion");
  set_short("A majin potion");
  set_long("This is a clear glass vial with the word 'Majin' on it.\n");
  set_type("sips");
  set_msg("You take a sip of the sickeningly bittersweet potion.\n");
  add_cmd("sip");
  add_cmd("drink");
  add_cmd("swig");
  set_heal(0,75);
  set_charges(3);
  set_soak(15);
  set_value(500);
}
