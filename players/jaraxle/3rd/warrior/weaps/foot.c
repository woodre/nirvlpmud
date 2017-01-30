#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("foot");
   set_alias("rabbits foot");
   set_short(BOLD+BLK+"Rabbits foot"+NORM);
   set_long("A "+BOLD+BLK+"black"+NORM+" rabbit's foot.\n");
   set_weight(1);
   set_value(170+random(100));
}

