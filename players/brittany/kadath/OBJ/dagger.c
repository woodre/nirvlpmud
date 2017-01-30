#include "/players/brittany/ansi"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dagger");
set_alias("sword");
set_short("Dagger");
set_long(
    "A short swordlike dagger, with a sharp bladed tip, a\n"+
    "pentagram is engraved on the handle.\n");

set_type("sword");  /*  sword/knife/club/axe/bow/polearm  */
set_class(10);
set_weight(2);
set_value(200);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(8);
if(W>6)  {
  say(
    "The dagger stabs you deeply, cutting savage rips into you.\n");

  write(
    "The dagger stabs deeply, cutting savage rips into its opponent.\n");
  return 3;
   }
return;
}
