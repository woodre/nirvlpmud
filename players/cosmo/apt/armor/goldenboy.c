#include "/players/cosmo/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
  set_name("boy");
  set_short(YEL+"Golden Boy"+NORM);
  set_alias("shirt");
  set_long(
    "\nA solid yellow T-shirt, previously owned by Jerry\n"+
    "Seinfeld. "+YEL+"Golden Boy"+NORM+" was Jerry's favorite shirt;\n"+
    "always the first one to be worn out of the wash.  It's\n"+
    "age is beginning to show however, as it frayed around the\n"+
    "edges.  Keep an eye out for "+BLU+"Baby Blue"+NORM+", "+YEL+"Golden Boy's"+
    NORM+"\nreplacement.  Both can easily be worn under your normal\n"+
    "armor for added comfort and protection.\n");
  set_ac(1);
  set_type("chest");
  set_weight(1);
  set_value(100);
  set_save_flag();
}

