#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("vita potion");
  add_alias("potion");
  add_alias("vita");
  set_short("A vita potion");
  set_long("This is a clear glass vial with the word 'Vita' on it.\n");
  set_type("sips");
  set_msg("You take a sip of the sickeningly bittersweet potion.\n");
  set_msg2(" drinks a potion.\n");
  add_cmd("sip");
  add_cmd("drink");
  add_cmd("swig");
  set_heal(75,0);
  set_charges(3);
  set_soak(15);
  set_value(600);
}
