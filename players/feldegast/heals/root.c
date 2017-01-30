#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("root");
  add_alias("tubor");
  add_alias("valdit");
  set_short(YEL+"Tubor root"+NORM);
  set_long("These tubor roots have been carefully gathered, aged, and prepared\n"+
           "in order to maximize their medicinal value.  It is said that a single\n"+
           "tubor root can bring a man back from the brink of death.");
  set_type("roots");
  set_msg("You chew on a tubor root.\n");
  set_msg2(" chews on a tubor root.\n");
  add_cmd("eat");
  add_cmd("chew");
  set_heal(45,25); /* 45 hp, 25 sp = 35 hp/sp */
  set_charges(5);
  set_intox(0);
  set_stuff(7);
  set_soak(0);
  set_value(560); /* per charge */
}

