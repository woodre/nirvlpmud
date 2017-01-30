#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A delphinium");
   set_long("Tall, green stems with purple flowers, which grow in groups.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "delphinium" || str == "flower"; }

