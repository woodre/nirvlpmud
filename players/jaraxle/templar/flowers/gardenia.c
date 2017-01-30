#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A gardenia flower");
   set_long("A collection of milky white petals wrapped around a green stem.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "gardenia" || str == "flower"; }

