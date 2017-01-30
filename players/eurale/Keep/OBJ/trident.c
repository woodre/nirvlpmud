#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("trident");
set_alias("emerald trident");
set_short(HIG+"Emerald Trident"+NORM);
set_long(
	"This sparkling green emerald trident is the favorite weapon of\n"+
	"the feared ghaggler.  It has 3 deadly, pronged and barbed tips\n"+
	"on the end of its sturdy handle.\n");
set_type("polearm");
set_class(18);
set_weight(6);
set_value(1550);
set_hit_func(this_object());
}

weapon_hit(attacker){
if(random(13) < 6) {
  say(
  "\nThe "+HIG+"TRIDENT"+NORM+" finds its mark....\n\n");

  write(
  "\nYour "+HIG+"TRIDENT"+NORM+" finds its mark.....\n\n");
  return 3; }
return;
}
