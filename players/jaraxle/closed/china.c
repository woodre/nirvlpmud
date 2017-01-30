#include "/players/jaraxle/define.h"
inherit "/obj/treasure";
object digimon;
reset(arg)  {
   
   set_short("A hooked cane");
   set_long("A cane you can use to 'call' a sheep.\n");
   set_weight(1);
   set_alias("cane");
   set_value(0);
}
id(str){ return str == "cane"; }

query_auto_load() {
   return "/players/jaraxle/closed/china.c:";
}

int drop(){ return 1; }
get(){ return 0; }

init() {
   add_action("call","call");
}

call(str){
   if(str != "sheep"){ notify_fail("Call what?\n"); return 0; }
   if(!str){ notify_fail("Call what?\n"); return 0; }
   digimon = clone_object("players/jaraxle/closed/sheep");
   digimon->patch_owner(this_player());
   move_object(digimon, environment(this_player()));
   write("You call a sheep to your side.\n");
   say(TPN+" raises the cane, and a sheep wanders in.\n");
   return 1; }
