#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_id("orb");
  set_short(HIC+"A glowing orb"+NORM);
  set_long(
    "This is a perfectly spherical orb that is glowing a faint blue.\n"
  );
  set_weight(1);
  set_value(100);
}
