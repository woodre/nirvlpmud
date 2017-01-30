/* Sand Squid Liver */
#include "defs.h"

inherit HEAL;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("liver");
  add_alias("squid liver");
  set_short(HIR+"Squid Liver"+NORM);
  set_long("This is the liver of a sand squid.  According to legend, the\n"+
           "liver of a sand squid has healing properties.\n");
  set_type("liver");
  set_msg("You slip the sand squid liver down your throat.  Mmm-good!\n");
  set_msg2(" eats some liver.\n");
  add_cmd("eat");
  add_cmd("chew");
  add_cmd("imbibe");
  set_heal(50,50);
  set_charges(1);
  set_stuff(18);
  set_value(500);
}
