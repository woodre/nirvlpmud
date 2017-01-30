/*  approved for play 9/24/98 - Eurale with a cost of 3000 coins */

#include "defs.h"

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("halberd");
  set_alias("polearm");
  set_short("Halberd");
  set_long(
"This halberd is an eight foot long polearm with a singlebladed axehead and\n"+
"a spike at the top.  It is a difficult weapon to use skillfully and\n"+
"requires a strong wielder to be used properly.\n");
  set_type("polearm");
  set_class(17);
  set_weight(5);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(this_player()->query_attrib("str") < 18) {
    if(!random(5))
      write("You fumble under the halberd's heavy weight.\n");
    return -2;
  }
  return 0;
}
