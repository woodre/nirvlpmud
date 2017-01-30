#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   call_out("self_destruct", 150); /* About 2.5 mins [enough for a fight or two] */
   call_out("emotes", 10);
   if(arg) return;
   set_alias("water");
   set_weight(1000000);
}
short(){ return "\t."+HIB+"~"+NORM+"."+HIB+"~ "+HIW+"water"+HIB+" ~"+NORM+"."+HIB+"~"+NORM; }
long(){ write("/n"); return 1; }
get(){ return 0; }
id(str){ return str == "water_element" || str == "water"; }

self_destruct(){
   say("As the "+HIB+"rains"+NORM+" cease, the lands becomes dry again.\n");
   destruct(this_object());
   return 1; }

emotes(){
   switch(random(6)){
      case 0 : say("Hard "+HIB+"rain"+NORM+" pelts at the ground.\n");
      break;
      case 1: say(HIB+"Water"+NORM+" passes over your feet.\n");
      break;
      case 2: say(HIB+"Rain"+NORM+" punishes the ground.\n");
      break;
      case 3: say("Steady "+HIB+"rain"+NORM+" floods the area.\n");
      break;
      case 4: say("The "+HIB+"rain"+NORM+" slows, drizzling over the area.\n");
      break;
      case 5: say("The "+HIB+"rain"+NORM+" picks up, drowning the area.\n");
      break;
   }
   remove_call_out("emotes");
   call_out("emotes",11);
}
