#include "defs.h"

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("pie");
  add_alias("pecan pie");
  add_alias("pecan");
  set_short("A slice of pecan pie");
  set_long("A slice of fresh baked pecan pie, wrapped in wax paper.\n");
  set_type("bites");
  set_msg("You take another bite of pecan pie.\n");
  set_msg2(" eats a bite of pecan pie.\n");
  add_cmd("eat");
  set_heal(50,50); /* hp,sp */
  set_charges(3);
  set_stuff(13);
  set_value(650); /* This is per charge */
}
