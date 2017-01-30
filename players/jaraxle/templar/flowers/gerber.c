#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A gerber daisy");
   set_long("A small flower with a brown center, surrounded by large yellow petals\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "gerber" || str == "gerber daisy" ||  str == "daisy" || str == "flower"; }

