#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A rose");
   set_long(RED+"A medium stemmed lusturious red rose.\n"+NORM);
   set_weight(1);
   set_value(0);
}
id(str){ return str == "rose" || str == "flower"; }

