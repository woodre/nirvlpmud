#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("spear");
  set_alias("polearm");
  set_short("Spear");
  set_long(
"The spear is a simple, yet elegant weapon, consisting\n"+
"of a long wooden shaft and a sharp spearhead at the tip.\n");
  set_type("polearm");
  set_class(15);
  set_weight(3);
  set_value(600);
}
