#include "/players/jaraxle/define.h"
inherit "obj/armor";

void
set_type(string str) {
   type = str;
}
reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("tail");
   set_alias("rabbit tail");
   set_id("tail");
   set_long(
      
      "This is a soft, bushy cotton tail.\n");
   
   set_ac(0);
   set_type("easter");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}
short(){ return ""+HIW+"Rabbit's tail"+NORM+""+(worn_by?" ("+HIW+"worn on hinie"+NORM+")":""); }

do_special(owner) {
   if(!random(6)) {
      tell_object(owner, "\t"+HIW+"You wiggle your tail happily.\n"+NORM);
      return 1; }
}
query_save_flag(){ return 1; }
init(){
   ::init();
   
   add_action("wiggle_it","wiggle");
   
}
wiggle_it(arg){
if(arg == "tail" || arg == "rabbit tail"){
write("You wiggle your cute tail.\n");
say(TPN+" wiggles "+POS+" cute rabbit's tail.\n");
return 1; }
}
