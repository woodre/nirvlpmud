#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A king protea");
   set_long("Large pink petals with a white center growing in a small bulb shape.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "king protea" || str == "flower"; }

