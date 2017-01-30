#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("jello");
set_short("Hat [dunce]");
set_long("Hat [dunce]");
   set_weight(0);
   set_value(0+random(0));
}
id(str){ return str == "hat" || str == "drag queen" || str == "pile of ashes" || str == "pile"; }

