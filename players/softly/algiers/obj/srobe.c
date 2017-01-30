#include "/players/softly/closed/ansi.h"

inherit "obj/armor.c";

reset(arg){


  set_name("silk robe");
  set_alias("robe");
  set_type("armor");
  set_short(BOLD+BLK+"Silk Robe"+NORM);
  set_long("A hand crafted silk robe.  This robe is\n"+
	   "very dense but very light.  It should provide some protection.\n");
  set_ac(5);
  set_weight(1);
  set_value(1200);
}

