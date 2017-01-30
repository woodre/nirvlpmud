/* Silver ring */

#include "/players/jareel/define.h"
inherit "obj/armor";

  reset(arg) {
    if(arg) return;
    ::reset();
  
  set_name("ring");
  set_alias("demon ring");
  set_short(HIK+"Demon Ring "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
  set_long(
      "Demon ring are forged in the Sun fires of Yelm. An ancient practice\n"+
      "that turns chaotic flesh into a protective shell.\n");
  set_ac(1);
  set_type("ring"); 
  set_weight(1);
  set_value(1200);
  set_arm_light(1);
  call_out("ringheal", 20);
}

ringheal(){
  if(!worn) return 0;
  if(worn && worn_by && random(2)){
    if(worn_by->query_hurt()){
      worn_by->add_sp(random(3)+2);
      tell_object(worn_by,
      "You feel a "+HIY+"warmth"+NORM+" spread up your arm.\n");
    }
  }
  call_out("ringheal", 20);
}

wear(str) {
while(remove_call_out("ringheal") != -1);
   if(!id(str) || environment() != this_player()) return 0;
 ::wear(str);
  if(worn) call_out("ringheal", 20);
 return 1;
}
remove(string str) {
   if(!id(str) || environment() != this_player() || !worn) return 0;
   ::remove(str);
   while(remove_call_out("ringheal") != -1);
   return 1;
}
