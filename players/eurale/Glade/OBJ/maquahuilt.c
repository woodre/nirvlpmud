#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("maquahuilt");
set_short("Maquahuilt");
set_long(
  "This sturdy wooden club has 'obsidian' blades set up and down its\n"+
  "entire length and around its top edges.\n");

set_type("club");  /*  sword/knife/club/axe/bow/polearm  */
set_class(16);
set_weight(3);
set_value(950 + random(100));
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  "The maquahuilt 'whistles' as it cuts through the air.\n");

  write(
  "The maquahuilt 'whistles' as it cuts through the air.\n");
  return 3;
   }
return;
}
