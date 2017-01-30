#include "/players/languilen/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("helmet");
set_alias("sparing helmet");
set_short("A Sparing helmet");
set_long(
  "This light weight gear is made to lesson shocks to the head.\n");

set_ac(1);
set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(20);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

