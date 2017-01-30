#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   call_out("self_destruct", 150); /* About 2.5 mins [enough for a fight or two] */
   call_out("emotes", 10);
   if(arg) return;
   set_alias("wind");
   set_long("An iron trinket with unknown markings.\n");
   set_weight(1000000);
}
short(){ return "\t."+HIC+"><"+NORM+"."+HIW+" wind "+NORM+"."+HIC+"><"+NORM; }
long(){ write("\n"); return 1; }
get(){ return 0; }
id(str){ return str == "wind_element" || str == "wind"; }

self_destruct(){
   say("The area settles down as the "+HIC+"wind"+NORM+" calm.\n");
   destruct(this_object());
   return 1; }

emotes(){
   switch(random(6)){
      case 0: say(HIC+"Winds"+NORM+" rip through the area.\n");
      break;
      case 1: say(HIC+"Winds"+NORM+" whip around you, tugging at your hair.\n");
      break;
      case 2: say("A light "+HIC+"breeze"+NORM+" whisks through the area.\n");
      break;
      case 3: say("Heavy "+HIC+"winds"+NORM+" whip through the area.\n");
      break;
      case 4: say("The "+HIC+"wind"+NORM+" assaults you, pushing you around.\n");
      break;
      case 5: say(HIC+"Wind"+NORM+" rips through the area.\n");
      break;
   }
   remove_call_out("emotes");
   call_out("emotes",11);
}
