inherit "/obj/generic_heal.c";
#include <ansi.h>

#include "../../defs.h"

int found;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("percocet");
  add_alias("bottle");
  add_alias("bottle of percocet");
  add_alias("medicine");
  add_alias("pill");
  set_short("Bottle of "+HIR+"Percocet"+NORM+"");
  set_long("Sweet relief from major aches & pains is only a swallow away.\n\
The expiration date is long past, so results may vary.\n");
  set_type("pill");
  set_msg("You swallow a "+HIR+"Percocet"+NORM+".\n");
  set_msg2(" swallows a "+HIR+"Percocet"+NORM+".\n");
  add_cmd("pop");
  add_cmd("gulp");
  add_cmd("swallow");
  set_heal(25+random(50),25+random(50));
  set_charges(1+random(4));
  set_stuff(0);
  set_soak(0);
  set_value(1800);
}

query_walker_value() { return found ? 1500 : (TIER_4_VALUE + random ( TIER_4_RAND )); }

query_save_flag() { return 1; }

set_found() { found = 1; }