#include "/players/languilen/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("pads");
set_alias("knee pads");
set_short("Knee Pads");
set_long(
  "These pastifoam pads will help protect your knees from injury.\n");

set_ac(1);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(20);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

