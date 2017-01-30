#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("trinket");
   set_short("An iron trinket");
   set_long("An iron trinket with unknown markings.\n");
   set_weight(1);
   set_value(100+random(51));
}
id(str){ return str == "iron" || str == "iron trinket" ||  str == "trinket"; }

