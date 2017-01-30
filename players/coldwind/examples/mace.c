#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("mace");
set_alias("weapon");
set_short(HIR+"Mace of the giant"+NORM);
set_long(HIR+
" A huge red mace made from a strange material. On its cold handle,\n"+
""+HIR+"in black letters, carved one word....\n"+
""+HIK+"                           A S H G A N                 \n"+NORM);
set_type("club");
set_class(16);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(20);
if(W>14)  {
  say(WHT+"You feel presence of dark forces.\n"+
  " \n"+
  " \n"+
  "              "+HIK+ attacker->query_name() + " is slammed to the ground by an invisible force."+NORM+"\n"+ 
  " \n"+
  " \n");

  write(WHT+"You feel presence of dark forces.\n"+
  " \n"+
  " \n"+
  "              "+HIK+ attacker->query_name() + " is slammed to the ground by an invisible force."+NORM+"\n"+
  " \n"+
  " \n");
  return 7;
   }
if(W>10)  {
  say(HIK+"Dark mist encircles "+user+"'s mace."+NORM+"\n"+
"                         "+HBWHT+HIB+" A S H G A N "+NORM+"\n"+ 
""+HIK+"                                "+ attacker->query_name() + " is hit by an invisible force."+NORM+"\n");

  write(HIK+"Dark mist encircles your mace."+NORM+"\n"+
"                         "+HBWHT+HIB+" A S H G A N "+NORM+"\n"+
""+HIK+"                                Your foe is hit by an invisible power."+NORM+"\n");
  return 3;
   }
return;
}
