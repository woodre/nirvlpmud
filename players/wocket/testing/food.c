#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/gendrink.c";

reset(arg){
  ::reset();
  if(arg) return;
set_name("food");
set_short(HIC+"Some food"+NORM+" (FOR TESTCHAR USE ONLY)");
set_cmd("eat");
set_alias("food");
set_strength(14);
set_heal(50);
set_charges(50);
set_cost(16);
set_type("eat_food");
}

query_weight(){ return 1; }
