#include "defs.h"

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("greaves");
  set_alias("tournament item");
  set_short("A pair of "+BOLD+"Silver greaves"+NORM);
  set_long(
    "This is a pair of chainmail greaves, or leg armor, with protective\n"+
    "plates at the joints and a pair of metal boots attached.\n"
  );
  set_ac(2);
  set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(0);
}

