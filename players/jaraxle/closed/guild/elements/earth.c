#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   call_out("self_destruct", 150); /* About 2.5 mins [enough for a fight or two] */
   call_out("emotes", 10);
   if(arg) return;
   set_alias("earth");
}
long(){ write("\n"); return 1; }
short(){ return "\t."+YEL+"-= "+HIW+"earth"+NORM+YEL+" =-"+NORM; }
id(str){ return str == "earth_element" || str == "earth"; }
get(){ return 0; }

self_destruct(){
   say("The "+YEL+"earth"+NORM+" settles back to normal.\n");
   destruct(this_object());
   return 1; }

emotes(){
   switch(random(6)){
      case 0 : say("The "+YEL+"earth"+NORM+" rumbles.\n");
      break;
      case 1: say("Small rocks drop from the pillars.\n");
      break;
      case 2: say("You hear the "+YEL+"earth"+NORM+" cracking.\n");
      break;
      case 3: say("The "+YEL+"earth"+NORM+" rumbles.\n");
      break;
      case 4: say("The "+YEL+"earth"+NORM+" shakes beneath your feet.\n");
      break;
      case 5: say("The "+YEL+"ground"+NORM+" trembles under you.\n");
      break;
   }
   remove_call_out("emotes");
   call_out("emotes",11);
}
