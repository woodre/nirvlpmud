#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("N");
set_alias("A");
set_short("S");
set_long(
  "desc. \n");

set_type("T");  /*  sword/knife/club/axe/bow/polearm  */
set_class(18);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(charges < 1) return;
charges-=;
if(W>9)  {
  say(
  "others hear.\n");

  write(
  "you hear. \n");
  return 3;
   }
return;
}

set_charges(int i){ charges = i; }
