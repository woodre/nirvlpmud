#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   call_out("self_destruct", 150); /* About 2.5 mins [enough for a fight or two] */
   call_out("emotes", 10);
   if(arg) return;
   set_alias("fire");
   set_weight(1000000);
}
short(){ return "\t."+HIR+"*"+NORM+"."+HIR+"* "+HIW+"fire "+HIR+"*"+NORM+"."+HIR+"*"+NORM; }
long(){ write("\n"); return 1; }
get(){ return 0; }
id(str){ return str == "fire_element" || str == "fire"; }

self_destruct(){
   say("The "+HIR+"fires"+NORM+" burn themselves out.\n");
   destruct(this_object());
   return 1; }

emotes(){
   switch(random(6)){
      case 0 : say(HIR+"Fire"+NORM+" burns in the area.\n");
      break;
      case 1: say(HIR+"Flames"+NORM+" lick close to your skin.\n");
      break;
      case 2: say("The "+HIR+"fires"+NORM+" crack and pop.\n");
      break;
      case 3: say("Incredible "+RED+"heat"+NORM+" fills the area.\n");
      break;
      case 4: say("The "+HIR+"fires"+NORM+" blaze relentlessly.\n");
      break;
      case 5: say(HIR+"Fires"+NORM+" burn wildly throughout the area.\n");
      break;
   }
   remove_call_out("emotes");
   call_out("emotes",11);
}
