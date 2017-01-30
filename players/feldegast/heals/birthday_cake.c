#include "defs.h"

inherit HEAL;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cake");
  add_alias("birthday cake");
  set_short("A "+HIC+"birthday"+YEL+" cake"+NORM);
  set_long("This is a beautiful birthday cake with icing and candles.\n");
  set_type("slices");
  set_msg("You eat some birthday cake.\n");
  set_msg2(" eats some birthday cake.\n");
  add_cmd("eat");
  add_cmd("fork");
  set_heal(35,35);
  set_charges(5);
  set_stuff(14);
  set_value(240);
}
