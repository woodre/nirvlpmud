inherit "obj/armor";
#include "/players/jareel/ansi.h"
reset() {
  set_name("tower shield");
  set_alias("shield");
  set_short(CYN+"Tin Tower Shield"+NORM);
  set_long(
      "This shield is formed from a very large piece of tin.\n"+
      "Having a mystically binding enchanted throughout the\n"+
      "metal, the shield can withstand a huge amount of damage.\n");
     set_ac(2);
  set_params("magical",2,0,0); /* <illarion> */
  set_type("shield");
  set_weight(1);
  set_value(3000);
}
