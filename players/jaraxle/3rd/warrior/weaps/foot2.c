#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("foot");
   set_alias("rabbits foot");
   set_short(HIW+"Rabbits foot"+NORM);
   set_long("A "+HIW+"white"+NORM+" rabbit's foot.\n");
   set_weight(1);
   set_value(40+random(80));
}
