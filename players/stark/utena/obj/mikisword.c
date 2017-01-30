inherit "obj/weapon.c";
#include "/players/stark/defs.h"
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("Fencing Foil");
set_alias("foil");
set_short("Fencing Foil");
set_long(
"   A weapon used for fencing.  A thin blade sharpened only at the \n"+
"tip.  The grip is slightly curved to fit the hand and heavy to \n"+
"counterbalance the weight of the blade.  A bowl shaped metal hand \n"+
"guard at the top of the grip to protect from attacks.\n");

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
  "   "+this_player()->query_name()+" steps in close to "+attacker->query_name()+" and slashes upwards\n");

  write(
  "   You step in close to "+attacker->query_name()+" and slash upwards\n");
  return 3;
   }
return;
}

