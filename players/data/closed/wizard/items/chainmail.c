#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("chainmail");
set_short("chainmail armor");
set_long(
  "This is an overshirt of chainmail armor.  It is made up of\n"+
  "thousands of small interlocking links of steel rings, which\n"+
  "are designed to protect versus some attacks.\n");
set_ac(2);
set_type("armor");
set_weight(2);
set_value(100);
}

	
