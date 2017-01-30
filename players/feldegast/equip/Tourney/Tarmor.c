#include "defs.h"

inherit "obj/armor";

reset(arg) {
  set_name("chainmail");
  set_alias("tournament item");
  set_short("A suit of "+BOLD+"Silver chainmail"+NORM);
  set_long(
    "This is a vest of silver chainmail with an extra layer of\n"+
    "boiled leather and an extra layer of cotton padding.  A\n"+
    "tabbard designed to be worn over it bears the crossed swords\n"+
    "and shield symbol of the tournament.\n"
  );
  set_ac(3);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(4);
  set_value(0);
}

