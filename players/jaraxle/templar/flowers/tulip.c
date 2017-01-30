#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A tulip");
   set_long("A long stemmed tulip.  This tulip has a thick white bulb which sits on a long green stem.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "tulip" || str == "flower" ||  str == "tulip"; }

