inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_long("zeus_sps_regen");
  set_weight(505031);
  set_value(0);
}

short(){ return 0; }
get(){ return 0; }
drop(){ return 1; }
can_put_and_get(){ return 0; }

id(str){ return str == "zeus_sps_regen"; }

  init(){
  ::init();
  add_action("swallow_pill", "swallow");
}


swallow_pill(){
  if((string)this_player()->query_real_name() != "zeus") return 0;
  write("You swallow the pill.\n");
  say(TP->QN+" casts a magical spell of sps regeneration.\n");
  call_out("sps_regen", 5);
return 1; }

sps_regen(){
object you, *thisroom;
int a,b,c;
if(!environment()) return;
if(living(environment())) return;
thisroom = all_inventory(environment());
a = sizeof(thisroom);
for(b = 0; b < a; b++){
you = thisroom[b];
if(living(you) && (you->query_sp() < you->query_msp())){
  you->add_spell_point(5+random(15));
  tell_object(you, "Your body tingles as your sps regenerate.\n");
}
}
call_out("sps_regen", 5+random(14));
}
