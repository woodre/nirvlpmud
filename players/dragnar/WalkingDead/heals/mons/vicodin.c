inherit "/obj/generic_heal.c";
#include <ansi.h>

#include "../../defs.h"

int found;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("vicodin");
  add_alias("bottle");
  add_alias("bottle of vicodin");
  add_alias("medicine");
  add_alias("pill");
  set_short("Bottle of "+HIB+"Vicodin"+NORM+"");
  set_long("Sweet relief from aches & pains is only a swallow away.\n\
The expiration date is long past, so results may vary.\n");
  set_type("pill");
  set_msg("You swallow a "+HIB+"Vicodin"+NORM+".\n");
  set_msg2(" swallows a "+HIB+"Vicodin"+NORM+".\n");
  add_cmd("pop");
  add_cmd("gulp");
  add_cmd("swallow");
  set_heal(random(100),random(100));
  set_charges(1+random(3));
  set_stuff(0);
  set_soak(0);
  set_value(2200);
}

query_walker_value() { return found ? 1500 : (TIER_3_VALUE + random ( TIER_3_RAND )); }

query_save_flag() { return 1; }

set_found() { found = 1; }