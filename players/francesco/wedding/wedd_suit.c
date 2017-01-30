#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("suit");
set_alias("tuxedo");
set_short(""+HIW+"A white tuxedo"+NORM+"");
set_long(
   "   Fantasy's ceremony dress is a white tuxedo, double-breasted,\n"+
   "with tails.  It is finely tailored and perfectly fits his body.\n");

set_ac(1);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(1000);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

