#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("hook");
set_alias("metal hook");
set_short("A curved metal hook");
set_long(
	  "  This curved metal hook has the edge of a razor.  It's talon\n"+
	"like point is also able to pierce tough materials.  It is the\n"+
	"prosthesis of Captain Hook.\n");
set_type("knife");
  set_class(18);
  set_weight(1);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>10)  {
  say(
  "\n\nThe hook "+BOLD+" L A C E R A T E S  "+NORM+" it's target.\n\n");

  write(
  "\n\nYou feel the hook "+BOLD+" L A C E R A T E "+NORM+" your target.\n\n");
  return 4;
   }
return;
}
