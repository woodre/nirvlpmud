#include "defs.h"

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  set_name("plate");
  set_alias("tournament item");
  set_short("A "+BOLD+"Silver breastplate"+NORM);
  set_long(
    "This is a thick plate made out of silver and with a chain vest\n"+
    "beneath it.  It comes with a thick cotton shirt as padding, and\n"+
    "a tabbard featuring the crossed swords and shield symbol of the\n"+
    "tournament which is designed to go over the plate.\n"
  );
  set_ac(4);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(4);
  set_value(0);
}

