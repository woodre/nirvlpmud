#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cloak");
  set_short(HIW+"White Tiger Cloak"+NORM);
  set_long(
    "This is a fur cloak made from the fur of a white tiger.\n"
  );
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(600);
}

