inherit "/obj/generic_heal.c";
#include <ansi.h>

#include "../../defs.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("advil");
  add_alias("bottle");
  add_alias("bottle of advil");
  add_alias("medicine");
  add_alias("pill");
  set_short("Bottle of "+YEL+"Advil"+NORM+"");
  set_long("Sweet relief from minor aches & pains is only a swallow away.\n\
The expiration date is long past, so results may vary.\n");
  set_type("pill");
  set_msg("You swallow an "+YEL+"Advil"+NORM+".\n");
  set_msg2(" swallows an "+YEL+"Advil"+NORM+".\n");
  add_cmd("pop");
  add_cmd("gulp");
  add_cmd("swallow");
  set_heal(random(100),0);
  set_charges(1+random(2));
  set_stuff(0);
  set_soak(0);
  set_value(1200);
}

query_walker_value() { return TIER_2_VALUE + random ( TIER_2_RAND ); }

query_save_flag() { return 1; }