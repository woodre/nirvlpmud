#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A snapdragon");
   set_long("A long green stem, with multiple bulbs of white flowers.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "snapdragon" || str == "flower"; }

