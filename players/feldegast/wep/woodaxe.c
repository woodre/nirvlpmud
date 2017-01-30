#include "/players/feldegast/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("axe");
  set_alias("woodaxe");
  set_short("Woodaxe");
  set_long(
"This is a single-bladed axe with a heavy blade for\n"+
"woodcutting.\n"
  );
  set_type("axe");
  set_class(16);
  set_weight(3);
  set_value(800);
}

