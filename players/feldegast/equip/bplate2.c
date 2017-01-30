#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("breastplate");
  set_alias("plate");
  set_short(BOLD+BLK+"A black breastplate"+NORM);
  set_long(
    "This is a thick, strong breastplate, suitable for a knight.  It is a\n"+
    "dull, charcoal shade of black, but seems to be in good condition.\n"
  );
  set_weight(4);
  set_ac(4);
  set_value(1500);
  set_type("armor");
}
