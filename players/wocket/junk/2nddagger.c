#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

int offwielded;
reset(arg){
  if(arg) return;
set_short(HIR+"2nddagger"+NORM);
set_name("dagger");
set_alias("pro_object");
set_alt_name("2nddagger");
set_class(17);
set_weight(1);
set_type("sword");
}

query_combat_method(){ return 3; }

drop(){
  this_player()->stop_offwielding();
  offwielded = 0;
  wielded = 0;
return 0;
}
dual_hit(){
int i;
i = random(5);
if(i == 0){
  write("You "+BOLD+"parry"+NORM+" and "+BOLD+"thrust"+NORM+" into your opponent.\n");
  say(this_player()->query_name()+" "+BOLD+"parries"+NORM+" and "+BOLD+" thrusts into "+this_player()->query_possesive()+" opponent.\n");
  return 10;
}
if(i == 1){
  write("You "+HIR+"slash"+NORM+" with your dagger "+HIR+"slicing"+NORM+" open your foe.\n");
  return 15;
}
if(i == 2){
  write("You thrust leaving yourself open for a counter attack.\n");
  return -3;
}
return 0;
}

init(){
  ::init();
add_action("offwield","offwield");
}

offwield(str){
if(!id(str)) return 0;
if(environment() != this_player()) return 0;
if(wielded){
  write("You can't offwield a wielded weapon.\n");
  return 1;
}
wielded_by = this_player();
call_other(this_player(),"offwield",this_object());
offwielded = 1;
wielded = 1;
return 1;
}

short(){
string sd;
sd = HIR+"2nddagger"+NORM;
if(wielded){
if(offwielded) return sd+" (offwielded)";
return sd+" (wielded)";
}
return sd;
}

query_offwielded(){ return offwielded; }
