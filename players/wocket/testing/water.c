#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/gendrink.c";

reset(arg){
  ::reset();
  if(arg) return;
set_name("water");
set_short(HIC+"Some water"+NORM+" (FOR TESTCHAR USE ONLY)");
set_alias("water");
set_cmd("drink");
set_strength(14);
set_heal(50);
set_charges(50);
set_cost(16);
set_type("drink_soft");
}

query_weight(){ return 1; }
