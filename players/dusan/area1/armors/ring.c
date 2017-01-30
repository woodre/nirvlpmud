#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
if(arg) return;
    ::reset();
set_name("ring");
set_alias("silver ring");
set_short("A silver ring");
set_long(
  "A thin silver band with delicate engravings.  It seems to be glowing\n"+
  "with some kind of minor enchantment. \n");
set_ac(1);
set_params("magical",1,0,0);
set_type("ring"); 
set_weight(1);
set_value(1200);
set_arm_light(1);
call_out("ringheal", 30);
}
/* Sloppy, let's fix this -Bp
ringheal(){
 if(worn && environment() && random(3)){
 environment()->add_hp(random(2)+1);
 tell_object(environment(),
 "You feel a "+CYN+"warmth"+NORM+" spread up your arm.\n");
}
call_out("ringheal", 30);
}
*/

ringheal(){
  if(!worn) return 0;
  if(worn && worn_by && random(3)){
    if(worn_by->query_hurt()){
      worn_by->add_hp(random(2)+1);
      tell_object(worn_by,
      "You feel a "+CYN+"warmth"+NORM+" spread up your arm.\n");
    }
  }
  call_out("ringheal", 30);
}

wear(str) {
while(remove_call_out("ringheal") != -1);
   if(!id(str) || environment() != this_player()) return 0;
 ::wear(str);
  if(worn) call_out("ringheal", 30);
 return 1;
}
remove(string str) {
   if(!id(str) || environment() != this_player() || !worn) return 0;
   ::remove(str);
   while(remove_call_out("ringheal") != -1);
   return 1;
}
