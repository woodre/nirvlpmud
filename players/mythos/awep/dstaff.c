#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("dreamstaff");
  set_alias("staff");
  set_short("Dream Staff");
  set_long("The staff is made from the stuff of dreams.\n"+
    "Many have seen this in their dreams but rarely \n"+
    "has one seen it.  It is of most exquisite beauty.\n");
  set_class(17);
  set_weight(2);
  set_type("staff");
  set_value(800);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(7);
if(W == 5)  {
  say("The staff bursts into flame.\n"+HIR+
    "\n~~~~~~~~~~~~~~~ FIRE ~~~~~~~~~~~~~~~\n\n"+NORM+
    "All is light and heat.\n");
write("The staff bursts into flame.\n"+HIR+
    "\n~~~~~~~~~~~~~~~ FIRE ~~~~~~~~~~~~~~~\n\n"+NORM+
    "The enemy is roasted.\n");
return 3;

   }
if(W == 6) {
  say(HIB+"\n\n\n           * *  *  *  F L A S H  *  *  * *\n\n\n"+NORM+
    "Light spears out from the staff... you are blinded momentarily.\n");
  write(HIB+"\n\n\n       * *  *  *  F L A S H  *  *  * *\n\n\n"+NORM+
  "A brilliant light spears out from the staff- your enemy is in pain.\n");
return 7;
}
   return;
}
