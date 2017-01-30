#include "/players/eurale/defs.h"
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
	"on the end of it's sturdy handle.\n");
set_type("polearm");
  set_class(18);
  set_weight(6);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  "\nThe "+HIG+"TRIDENT"+NORM+" finds it's mark....\n\n");

  write(
  "\nYour "+HIG+"TRIDENT"+NORM+" finds it's mark.....\n\n");
  return 3;
   }
return;
}

init() {
move_object(clone_object("players/eurale/Keep/OBJ/trident"),this_player());
destruct(this_object());
}
