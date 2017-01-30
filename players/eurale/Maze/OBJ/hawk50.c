/*  A Hawkings 50 cal long rifle  (WC 18 - saveable)  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("rifle");
set_alt_name("gun");
  set_alias("long rifle");
  set_short("A Hawkings 50 cal long rifle");
set_long(
	"  The beautiful rifle has a long steel barrel and a solid black \n"+
	"walnut stock.  The barrel is well oiled and the mechanism works \n"+
	"smoothly and quietly... a deadly weapon at any range. \n");
set_type("bow");
  set_class(18);
  set_weight(3);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say("\nThe mighty rifle recoils with a..... \n\n"+
        "        ssssssssskkkkk...... "+CYN+"KAAAAABBBOOOOOOOMMM!!!"+NORM+"\n\n");

  write("\nYou feel the jerk as the rifle spits it's bullet... KABOOM!\n\n");
  return 5;
   }
   return;
}
