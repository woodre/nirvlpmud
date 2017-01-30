#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("scimitar");
  set_short("A steel scimitar");
  set_long(
    "This is a well-made, but otherwise unremarkable scimitar.  It has\n"+
    "a single edge and a curved blade heavily weighted at the point.\n"
  );
  set_type("sword");
  set_class(17);
  set_weight(3);
  set_value(590+random(20));
}
