#include "defs.h"

inherit "obj/armor";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("leather");
  set_alias("leather armor");
  set_short(BLK+BOLD+"Black leather armor"+NORM);
  set_long(
    "This is a skintight suit of black leather armor.\n"
  );
  set_ac(2);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(250);
}
