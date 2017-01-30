/* Golden Earring */

#include "/players/jareel/define.h"
inherit "obj/armor";

  reset(arg) {
    if(arg) return;
    ::reset();
  
  set_name("earring");
  set_alias("demon ring");
  set_short(HIK+"Demon Earrings "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
  set_long(
      "Demon Earrings are forged in the sun fires of Yelm. An ancient practice\n"+
      "that turns chaotic flesh into a protective shell.\n");
  set_ac(1);
  set_type("earring"); 
  set_weight(1);
  set_value(21200);
  set_arm_light(1);
  call_out("ringheal", 20);
}

ringheal(){
  if(!worn) return 0;
  if(worn && worn_by && random(2)){
    if(worn_by->query_hurt()){
      worn_by->add_sp(random(3)+2);
      tell_object(worn_by,
      "You feel a "+HIY+"warmth"+NORM+" spreads over your face.\n");
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
