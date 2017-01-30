#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("skeleton");
  set_short(HIW+"A human skeleton"+NORM);
  set_long("A pile of human bones.\n");
   set_weight(1);
   set_value(10+random(10));
}
id(str){ return str == "skeleton"; }

