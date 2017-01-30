#include "defs.h"

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("juice");
  add_alias("jug");
  add_alias("blackberry juice");
  add_alias("jug of blackberry juice");
  set_short("A jug of blackberry juice");
  set_long("This is an earthenware jug with a blackberry painted on it.\n");
  set_type("sips");
  set_msg("You take a swig of blackberry juice.\n");
  set_msg2(" drinks some juice.\n");
  add_cmd("swig");
  add_cmd("drink");
  add_cmd("sip");
  set_heal(35,35);
  set_charges(5);
  set_soak(14);
  set_value(240);
}
