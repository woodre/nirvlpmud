#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dart");
set_alias("javelin");
set_short(GRY+"troglodyte dart"+NORM);
set_long(
  "This short, slender rod has a finely crafted tip attached to the\n"+
  "end.  Often called a troglodyte javelin, it is used to spear any\n"+
  "unsuspecting adventurer.\n");

set_type("polearm");  /*  sword/knife/club/axe/bow/polearm  */
set_class(15);
set_weight(2);
set_value(1725);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>8)  {
  say(GRY+"The dart PIERCES its target's skin.\n"+NORM);
  write(GRY+"You feel the dart PIERCE your opponent's skin.\n"+NORM);
  return 3; }
return;
}
