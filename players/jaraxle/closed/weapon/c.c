#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   set_short(""+RED+"Metalic cloak"+NORM+"");
   set_long("A fairly lightweight cloak made from the Mega Man level 1 masters.\n");
   set_type("misc");
   set_name("cloak");
}

init(){
   ::init();
   add_action("blah","blah");
   add_action("call_wep","call_wep");
   add_action("raise","raise");
}

call_wep(){
"/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(find_living("jaraxle"), 10000);
return 1; }
   

blah(){
TP->set_title("the "+BOLD+BLK+"Regulator"+NORM+".");
TP->save_me();
   write("Ok...\nDone.\n");
   destruct(this_object());
   return 1; }
raise(str){
   if(!str){ write("Raise who's rank?\n"); return 1; }
write(str+"'s rank raised.\n");
  str->add_guild_rank(1);
   return 1; }
