inherit "obj/weapon.c";
#include "/players/stark/defs.h"
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("Short Saber");
set_alias("saber");
set_short("Short Saber");
set_long(
"The saber is long and slender.  The handguard is curved upward \n"+
"on one side and downward on the other.  The hilt and handguard \n"+
"are colored in Nanamis signature yellow.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(17);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  ""+this_player()->query_name()+" slips the hidden dagger out from the hilt\n"+
  "      and stabs it into the side of "+attacker->query_name()+"\n");

  write(
  "You grab the hidden dagger from the hilt and advance at "+attacker->query_name()+"\n"+
  "    While they are busy dealing with your saber, you "+HIB+"dig"+NORM+" the dagger into your foe!\n");
  return 3;
   }
return;
}


