#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

  set_id("skin");
  set_alias("snake skin");
  set_short("Snake skin");
set_long("A sliver of snakes skin.\n");
   set_weight(1);
  set_value(450+random(100));
}
