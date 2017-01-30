
inherit "obj/weapon.c";
#include "/players/eurale/closed/ansi.h"

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("revolver");
  set_alias("gun");
set_short(".44 cal revolver");
set_long(
	"  This rugged hand gun is ahead of it's time.  It's revolving \n"+
	"cylinder allows the shooter to fire repeatedly.  The notches \n"+
	"in the hand grip indicate it's ability to kill... \n");

set_type("bow");
set_class(16);
set_weight(1);
set_value(900);
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>10)  {
  say("\nThe big handgun fires.... "+HIW+"KABOOM...KABOOM...KABOOM\n\n"+NORM);

  write("\nYour wrist jerks... "+HIW+"KABOOM....KABOOM....KABOOM\n\n"+NORM);
  return 4;
   }
return;
}
