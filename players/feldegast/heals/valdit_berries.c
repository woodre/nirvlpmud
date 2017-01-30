#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("berries");
  add_alias("berry");
  add_alias("valdit");
  set_short(HIR+"Valdit berries"+NORM);
  set_long("The valdit is a bright red berry with streaks of purple\n"+
           "running through it.  It is prized both for its rarity\n"+
           "and its supposedly mysticical healing abilities.\n");
  set_type("berries");
  set_msg("You stuff a handful of valdit berries in your mouth.\n");
  set_msg2(" eats a handful of valdit berries.\n");
  add_cmd("eat");
  set_heal(50,50);
  set_charges(3);
  set_intox(0);
  set_stuff(4);
  set_soak(0);
  set_value(1500); /* per charge */
}
