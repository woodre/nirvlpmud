#include "defs.h"

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("gauntlets");
  set_alias("tournament item");
  set_short("A pair of "+BOLD+"Silver gauntlets"+NORM);
  set_long(
    "A pair of silver gauntlets with the crossed swords and shield symbol\n"+
    "of the tourney on the back of either hand.\n"
  );
  set_ac(2);
  set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(0);
}
