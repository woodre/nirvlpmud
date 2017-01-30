#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("axe");
  set_alias("halfaxe");
  set_short("A half-moon axe");
  set_long(
    "This is a heavy iron axe with a long shaft and a blade in the\n"+
    "shape of a half-moon.\n"
  );
  set_type("axe");
  set_class(17);
  set_weight(3);
  set_value(590+random(20));
}
