#include "/players/pavlik/closed/colors.h"
#define IT capitalize(attacker->query_name())
#define ME capitalize(this_player()->query_name())
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name(HIR+"Lava "+HIW+"Staff"+NORM);
  set_alt_name("lava staff");
  set_short(HIR+"Lava "+HIW+"Staff"+NORM);
  set_long(
    "This staff is made of hardened lava.  The lava staff is slightly\n"+
    "awkward to wield because of its weight, but it is obvious what a good\n"+
    "hit with this staff would do to ones enemy.\n");
  set_type("staff");
  set_class(16+random(3));
  set_weight(3);
  set_value(750);
  set_save_flag(0);
  set_hit_func(this_object());
}

weapon_hit(attacker){
  if(random(50) >= 40) {
	write("You BASH your enemy with the lava staff!\n");
	return 7;
  }
}

