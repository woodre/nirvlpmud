#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("mummy ashes");
   set_short("A pile of ashes");
   set_long("A dark black mound of ashes.\n");
   set_weight(1);
   set_value(1+random(10));
}
id(str){ return str == "ashes" || str == "mound" || str == "pile of ashes" || str == "pile"; }

