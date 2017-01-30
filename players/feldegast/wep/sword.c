#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sword");
  set_short("A steel broadsword");
  set_long(
    "This is a strong steel broadsword with a brass crosspiece\n"+
    "and a leather grip.\n"
  );
  set_type("sword");
  set_class(17);
  set_weight(3);
  set_value(550+random(100));
}
