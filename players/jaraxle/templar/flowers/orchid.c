#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("An orchid");
   set_long("A small group of white petaled flowers with a yellow center.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "orchid" || str == "flower"; }

