#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("metal tool");
set_alias("tool");
set_short("A long metal tool");
set_long(
  "This 6 foot long metal bar has a flattened blade on one end and is\n"+
  "slightly curved.  I looks as though it may have been used to pry\n"+
  "large logs into position for building as there are bark remnants\n"+
  "still stuck to it along its length.\n");

set_type("club");  /*  sword/knife/club/axe/bow/polearm  */
set_class(15);
set_weight(3);
set_value(525);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>8)  {
  say(
  "The rod hits its target with a SICKENING THUD!!\n\n");

  write(
  "You hear a SICKENING THUD as you strike your target!\n\n");
  return 3;
   }
return;
}
