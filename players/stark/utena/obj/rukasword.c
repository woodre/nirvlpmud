inherit "obj/weapon.c";
#include "/players/stark/defs.h"
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("Fencing Foil");
set_alias("foil");
set_short("Fencing Foil");
set_long(
/*1234567890123456789012345678901234567890123456789012345678901234567890*/
"   A weapon used for fencing.  A thin blade sharpened only at the \n"+
"tip.  The grip is slightly curved to fit the hand and heavy to \n"+
"counterbalance the weight of the blade.  A bowl shaped metal hand \n"+
"guard at the top of the grip to protect from attacks.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(18);
set_weight(3);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  "   "+this_player()->query_name()+" stares down into the eyes of "+attacker->query_name()+"\n"+
  "       and "+RED+"lunges"+NORM+" the blade in deep!\n");

  write(
  "   You stare down into the eyes of "+attacker->query_name()+"\n"+
  "       and "+RED+"lunge"+NORM+" the tip of the blade deep into their body!\n");
  return 3;
   }
return;
}

