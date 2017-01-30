#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("vase");
   set_short("A vase");
  set_long("A fragile vase made from spun clay.\nThere are egyptian markings on the vase.\n");
   set_weight(1);
   set_value(125+random(26));
}
id(str){ return str == "vase"; }

