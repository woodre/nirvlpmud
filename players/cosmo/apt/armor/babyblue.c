#include "/players/cosmo/closed/ansi.h"
inherit "obj/armor";
reset(arg) {
  set_name("blue");
  set_short(BLU+"Baby Blue"+NORM);
  set_alias("shirt");
  set_long(
    "\nA solid light blue T-shirt, previously owned by Jerry\n"+
    "Seinfeld. "+BLU+"Baby Blue"+NORM+" is the successor to "+YEL+"Golden Boy"+
    NORM+".\n  This shirt looks and feels brand new, and since it is\n"+
    "made of the softest available cotton, it is ultra-comfortable.\n"+
    "It can easily be worn under your normal armor for added\n"+
    "comfort and protection.\n");
  set_ac(1);
  set_type("chest");
  set_weight(1);
  set_value(200);
  set_save_flag();
}

