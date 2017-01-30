#include "/players/languilen/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("stick");
set_alias("pugil stick");
set_short("Pugil stick");
set_long(
  "This four foot long stick has thick padding on both ends.  Because it\n"+
  "won't cut it is used by many for practice combat.  Even so it is still\n"+
  "dangerous and in the right hands can knock the stuffing out of an opponent.\n");

set_type("club");  /*  sword/knife/club/axe/bow/polearm  */
set_class(16);
set_weight(2);
set_value(0);
set_hit_func(this_object());
}

weapon_hit(attacker){
int d;
d = random(13);
if(d>9)  {
  say(
  "The pugil connects with a solid blow.\n");

  write(
  "You connect with a solid blow. \n");
  return 2;
   }
return;
}
