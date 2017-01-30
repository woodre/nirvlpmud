#include "/players/brittany/ansi"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("translucent bow");
set_alias("bow");
set_short(""+HIG+"Translucent bow"+NORM+"");
set_long(
    "A diffusing bow with propelling poisionous arrows.\n");

set_type("bow");  /*  sword/knife/club/axe/bow/polearm  */
set_class(15);
set_weight(4);
set_value(500);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(9);
if(W>7)  {
  say(
    "Hard thrusts of posionous arrows shoots into you.\n");

  write(
    "Hard thrusts of posionous arrows shoots into its opponent.\n");
  return 3;
   }
return;
}
